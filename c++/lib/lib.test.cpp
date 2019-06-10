#include <boost/test/unit_test.hpp>
#include <lib/lib.hpp>

BOOST_AUTO_TEST_CASE(test_diagonal_difference)
{
  using namespace xzr::lib;
  {
    const std::vector<std::vector<int>> arr{ { 1, 0 }, { 0, 1 } };
    BOOST_TEST(diagonal_difference(arr) == 2);
  }
  {
    const std::vector<std::vector<int>> arr{ { 0, 1 }, { 1, 0 } };
    BOOST_TEST(diagonal_difference(arr) == 2);
  }
  {
    const std::vector<std::vector<int>> arr{ { 11, 2, 4 },
                                             { 4, 5, 6 },
                                             { 10, 8, -12 } };
    BOOST_TEST(diagonal_difference(arr) == 15);
  }
}
