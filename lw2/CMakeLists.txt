cmake_minimum_required(VERSION 3.29)
project(PPOIS_lw2_sem3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -Wall -Wextra -Werror -Wpedantic")

include_directories(include)

add_library(RepairCompany SHARED
        src/carpenter.cc
)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include(GoogleTest)

add_executable(tests
        tests/RUN_ALL_TESTS.cc
        tests/carpenter_tests.cc
)

target_link_libraries(tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(tests)