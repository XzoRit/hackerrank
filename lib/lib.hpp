#include <boost/mp11.hpp>

#include <algorithm>
#include <cmath>
#include <iterator>
#include <numeric>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

template<class Container>
using cont_size_type = typename Container::size_type;

template<class Iter>
using iter_difference_type =
  typename std::iterator_traits<Iter>::difference_type;

namespace xzr
{
namespace lib
{
namespace impl
{
inline const auto inc = [](auto& a) mutable { ++a; };

inline const auto dec = [](auto& a) mutable { --a; };

inline const auto pos = [](auto&& a) { return a > 0; };

inline const auto neg = [](auto&& a) { return a < 0; };

inline const auto eq_0 = [](auto&& a) { return a == 0; };

inline const auto sum_diagonal =
  [](const auto& matrix, auto start_index, auto next_index) {
    using size_type = cont_size_type<std::decay_t<decltype(matrix)>>;
    using value_type = std::decay_t<decltype(matrix[size_type{}][size_type{}])>;

    value_type sum{};

    for (size_type a{}, b{ start_index }; a < matrix.size(); ++a, next_index(b))
    {
      sum += matrix[a][b];
    }

    return sum;
  };

inline const auto sum_diagonal_left_to_right = [](const auto& matrix) {
  return sum_diagonal(matrix, 0u, inc);
};

inline const auto sum_diagonal_right_to_left = [](const auto& matrix) {
  return sum_diagonal(matrix, matrix.size() - 1, dec);
};

using boost::mp11::mp_for_each;
using boost::mp11::mp_iota_c;
using boost::mp11::mp_repeat_c;

template<class T, std::size_t N>
using tuple_repeat_c = mp_repeat_c<std::tuple<T>, N>;

template<std::size_t N, class F>
constexpr F for_each_index(F&& f)
{
  return mp_for_each<mp_iota_c<N>>(std::forward<F>(f));
}

template<class Iter, class Sent, class... Preds>
auto count_all(Iter b, Sent e, std::tuple<Preds...>&& preds)
  -> tuple_repeat_c<iter_difference_type<Iter>, sizeof...(Preds)>
{
  constexpr std::size_t N{ sizeof...(Preds) };
  using counts_t = tuple_repeat_c<iter_difference_type<Iter>, N>;

  counts_t counts{};
  for (; b != e; ++b)
  {
    for_each_index<N>([&](auto I) mutable {
      if (std::get<I>(preds)(*b)) ++std::get<I>(counts);
    });
  }

  return counts;
}

template<class Cont, class Preds>
auto count_all(const Cont& cont, Preds&& preds)
{
  return count_all(begin(cont), end(cont), std::forward<Preds>(preds));
}
}

inline namespace v1
{
inline const auto diagonal_difference = [](const auto& matrix) {
  return std::abs(
    impl::sum_diagonal_left_to_right(matrix) -
    impl::sum_diagonal_right_to_left(matrix));
};

inline const auto staircase = [](auto steps) {
  std::vector<int> v(steps);
  std::iota(begin(v), end(v), 1);

  return std::accumulate(
    begin(v), end(v), std::string{}, [steps](const auto& a, const auto& stair) {
      const std::string space_chars(steps - stair, ' ');
      const std::string stair_chars(stair, '#');
      return a + space_chars + stair_chars + '\n';
    });
};

inline const auto mini_max_sum = [](std::vector<int> nums) {
  const auto& sum{ std::accumulate(begin(nums), end(nums), std::int64_t{}) };
  const auto& min_max{ std::minmax_element(begin(nums), end(nums)) };
  return std::make_pair(sum - *min_max.second, sum - *min_max.first);
};

template<class Cont>
auto plus_minus(const Cont& nums)
{
  const auto size{ static_cast<double>(nums.size()) };
  if (size == 0) return std::make_tuple(0., 0., 0.);

  const auto& counts{ impl::count_all(
    nums, std::make_tuple(impl::pos, impl::neg, impl::eq_0)) };

  return std::make_tuple(
    std::get<0>(counts) / size,
    std::get<1>(counts) / size,
    std::get<2>(counts) / size);
}
}
}
}
