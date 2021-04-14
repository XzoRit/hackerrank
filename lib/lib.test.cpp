#include <lib/lib.hpp>

#include <boost/test/unit_test.hpp>

#include <array>
#include <vector>

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

BOOST_AUTO_TEST_CASE(test_staircase)
{
  using namespace xzr::lib;
  {
    BOOST_TEST(staircase(0) == "");
    BOOST_TEST(staircase(1) == "#\n");
    BOOST_TEST(staircase(2) == " #\n##\n");
    BOOST_TEST(staircase(3) == "  #\n ##\n###\n");
  }
}

BOOST_AUTO_TEST_CASE(test_mini_max_sum)
{
  using namespace xzr::lib;
  {
    BOOST_TEST(mini_max_sum({ 1, 2, 3, 4, 5 }).first == 10);
    BOOST_TEST(mini_max_sum({ 1, 2, 3, 4, 5 }).second == 14);
  }
  {
    // results can be bigger than int-max
    BOOST_TEST(
      mini_max_sum({ 256741038, 623958417, 467905213, 714532089, 938071625 })
        .first == 2063136757);
    BOOST_TEST(
      mini_max_sum({ 256741038, 623958417, 467905213, 714532089, 938071625 })
        .second == 2744467344);
  }
}

BOOST_AUTO_TEST_CASE(test_plus_minus)
{
  using namespace xzr::lib;
  BOOST_TEST(
    plus_minus({}) == (std::array{ 0., 0., 0. }),
    boost::test_tools::per_element());
  BOOST_TEST(
    plus_minus({ 1, 1 }) == (std::array{ 1., 0., 0. }),
    boost::test_tools::per_element());
  BOOST_TEST(
    plus_minus({ 1, 1, -1, -1 }) == (std::array{ .5, .5, 0. }),
    boost::test_tools::per_element());
  BOOST_TEST(
    plus_minus({ 1, 1, 1, -1, -1, -1, 0, 0, 0 }) ==
      (std::array{ 3 / 9., 3 / 9., 3 / 9. }),
    boost::test_tools::per_element());
}
