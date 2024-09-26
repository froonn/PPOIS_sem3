cmake_minimum_required(VERSION 3.28)
project(real_matrix)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -Werror")

include_directories(include)

add_library(real_matrix src/real_matrix.cpp src/real_matrix_ROW.cpp)

enable_testing()
find_package(UnitTest++ REQUIRED)
add_executable(real_matrix_tests tests/real_matrix_tests.cpp)
target_link_libraries(real_matrix_tests real_matrix UnitTest++)
add_test(NAME real_matrix_tests COMMAND real_matrix_tests)