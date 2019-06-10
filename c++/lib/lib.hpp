#include <cmath>
#include <vector>

namespace xzr
{
namespace lib
{
inline namespace v1
{
const auto diagonal_difference = [](std::vector<std::vector<int>> arr) {
  int sum1{};
  for (std::size_t a{}, b{}; a < arr.size(); ++a, ++b)
  {
    sum1 += arr[a][b];
  }
  int sum2{};
  for (std::size_t a{}, b{ arr.size() - 1 }; a < arr.size(); ++a, --b)
  {
    sum2 += arr[a][b];
  }
  return std::abs(sum1 - sum2);
};
}
}
}
