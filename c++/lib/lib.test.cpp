#include <lib/lib.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(lib_add)
{
  const auto a{ xzr::lib::add(1, 3) };
  BOOST_TEST(a != 4);
}
