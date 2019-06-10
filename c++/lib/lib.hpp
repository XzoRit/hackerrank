#include <cmath>
#include <type_traits>

namespace xzr
{
namespace lib
{
namespace impl
{
const auto sum_diagonal =
  [](const auto& matrix, auto start_index, auto next_index) {
    using size_type = typename std::decay_t<decltype(matrix)>::size_type;
    using value_type = std::decay_t<decltype(matrix[size_type{}][size_type{}])>;
    value_type sum{};
    for (size_type a{}, b{ start_index }; a < matrix.size(); ++a, next_index(b))
    {
      sum += matrix[a][b];
    }
    return sum;
  };
const auto inc = [](auto& a) mutable { ++a; };
const auto dec = [](auto& a) mutable { --a; };
const auto sum_diagonal_left_to_right = [](const auto& matrix) {
  return sum_diagonal(matrix, 0u, inc);
};
const auto sum_diagonal_right_to_left = [](const auto& matrix) {
  return sum_diagonal(matrix, matrix.size() - 1, dec);
};
}
inline namespace v1
{
const auto diagonal_difference = [](const auto& matrix) {
  return std::abs(
    impl::sum_diagonal_left_to_right(matrix) -
    impl::sum_diagonal_right_to_left(matrix));
};
}
}
}
