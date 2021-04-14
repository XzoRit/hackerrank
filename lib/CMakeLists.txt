set(
  src_dir
  ${CMAKE_CURRENT_SOURCE_DIR}
)

set(
  inc_dir
  ${src_dir}/..
)

add_library(
  lib
)

target_sources(
  lib
  PRIVATE
  "${src_dir}/lib.cpp"
  "${src_dir}/lib.hpp"
)

target_include_directories(
  lib
  PUBLIC
    ${inc_dir}
)

target_link_libraries(
  lib
  PUBLIC
    Boost::boost
)

add_library(
  lib::lib
  ALIAS
  lib
)

add_executable(
  lib_test
)

target_sources(
  lib_test
  PRIVATE
  "${src_dir}/lib.test.cpp"
  "${src_dir}/main.test.cpp"
)

target_link_libraries(
  lib_test
  PRIVATE
    lib::lib
    Boost::boost
    Boost::unit_test_framework
)

add_test(
  NAME
    lib::test
  COMMAND
    lib_test
    "--color_output=false"
)
