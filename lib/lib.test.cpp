#include <lib/lib.hpp>

#include <boost/mp11.hpp>
#include <boost/test/unit_test.hpp>

#include <array>
#include <libs/test/include/boost/test/unit_test_suite.hpp>
#include <ostream>
#include <vector>

namespace std
{
template <class... T>
ostream& operator<<(ostream& o, const tuple<T...>& tp)
{
    using boost::mp11::mp_for_each;
    using boost::mp11::mp_iota_c;

    constexpr size_t N = sizeof...(T);

    mp_for_each<mp_iota_c<N>>([&](auto I) { o << std::get<I>(tp) << ' '; });

    return o;
}
} // namespace std

namespace
{
using namespace xzr::lib;

BOOST_AUTO_TEST_CASE(test_diagonal_difference)
{
    {
        const std::vector<std::vector<int>> arr{{1, 0}, {0, 1}};
        BOOST_TEST(diagonal_difference(arr) == 2);
    }
    {
        const std::vector<std::vector<int>> arr{{0, 1}, {1, 0}};
        BOOST_TEST(diagonal_difference(arr) == 2);
    }
    {
        const std::vector<std::vector<int>> arr{{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};
        BOOST_TEST(diagonal_difference(arr) == 15);
    }
}

BOOST_AUTO_TEST_CASE(test_staircase)
{
    BOOST_TEST(staircase(0) == "");
    BOOST_TEST(staircase(1) == "#\n");
    BOOST_TEST(staircase(2) == " #\n##\n");
    BOOST_TEST(staircase(3) == "  #\n ##\n###\n");
}

BOOST_AUTO_TEST_CASE(test_mini_max_sum)
{
    {
        BOOST_TEST(mini_max_sum({1, 2, 3, 4, 5}).first == 10);
        BOOST_TEST(mini_max_sum({1, 2, 3, 4, 5}).second == 14);
    }
    {
        // results can be bigger than int-max
        BOOST_TEST(mini_max_sum({256741038, 623958417, 467905213, 714532089, 938071625}).first == 2063136757);
        BOOST_TEST(mini_max_sum({256741038, 623958417, 467905213, 714532089, 938071625}).second == 2744467344);
    }
}

BOOST_AUTO_TEST_CASE(test_plus_minus)
{
    BOOST_TEST(plus_minus(std::array<int, 0>{}) == std::make_tuple(0., 0., 0.));
    BOOST_TEST(plus_minus(std::array{1, 1}) == std::make_tuple(1., 0., 0.));
    BOOST_TEST(plus_minus(std::array{1, 1, -1, -1}) == std::make_tuple(.5, .5, 0.));
    BOOST_TEST(plus_minus(std::array{1, 1, 1, -1, -1, -1, 0, 0, 0}) == std::make_tuple(3 / 9., 3 / 9., 3 / 9.));
}

BOOST_AUTO_TEST_CASE(test_time_conversion)
{
    BOOST_TEST(time_conversion("07:05:45AM") == "07:05:45");
    BOOST_TEST(time_conversion("07:05:45PM") == "19:05:45");

    BOOST_TEST(time_conversion("12:00:00PM") == "12:00:00");
    BOOST_TEST(time_conversion("12:00:00AM") == "00:00:00");

    BOOST_TEST(time_conversion("12:00:01PM") == "12:00:01");
    BOOST_TEST(time_conversion("12:00:01AM") == "00:00:01");
}

BOOST_AUTO_TEST_CASE(test_cpp_variadic)
{
    BOOST_TEST((reversed_binary_value<0>()) == 0);
    BOOST_TEST((reversed_binary_value<1>()) == 1);
    BOOST_TEST((reversed_binary_value<1, 0>()) == 1);
    BOOST_TEST((reversed_binary_value<1, 0, 0>()) == 1);
    BOOST_TEST((reversed_binary_value<0, 1>()) == 2);
    BOOST_TEST((reversed_binary_value<1, 1>()) == 3);
    BOOST_TEST((reversed_binary_value<0, 0, 1>()) == 4);

    static_assert(reversed_binary_value<0, 0, 1>() == 4);
}
} // namespace
