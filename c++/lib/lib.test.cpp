#include <boost/test/unit_test.hpp>
#include <lib/lib.hpp>

BOOST_AUTO_TEST_CASE(diagonal_difference)
{
  {
    const std::vector<std::vector<int>> arr{ { 1, 0 }, { 0, 1 } };
    const auto a{ xzr::lib::diagonal_difference(arr) };
    BOOST_TEST(a == 2);
  }
  {
    const std::vector<std::vector<int>> arr{ { 0, 1 }, { 1, 0 } };
    const auto a{ xzr::lib::diagonal_difference(arr) };
    BOOST_TEST(a == 2);
  }
}
