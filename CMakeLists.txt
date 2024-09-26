cmake_minimum_required(VERSION 3.28)
project(PPOIS_sem3)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra -Werror")

include_directories(real_matrix/include)
link_directories(real_matrix/build)

add_executable(real_matrix_example main.cpp)

target_link_libraries(real_matrix_example real_matrix)