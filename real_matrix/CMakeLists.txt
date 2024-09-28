cmake_minimum_required(VERSION 3.28)
project(real_matrix)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -Werror")

include_directories(include)

add_library(real_matrix src/Real_matrix.cpp src/Row.cpp)
set_target_properties(real_matrix PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ../lib)


enable_testing()
find_package(UnitTest++ REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -lgcov")

add_executable(real_matrix_tests tests/Real_matrix_tests.cpp)
target_link_libraries(real_matrix_tests real_matrix UnitTest++)
add_test(NAME real_matrix_tests COMMAND real_matrix_tests)

add_executable(row_tests tests/Row_tests.cpp)
target_link_libraries(row_tests real_matrix UnitTest++)
add_test(NAME row_tests COMMAND row_tests)


