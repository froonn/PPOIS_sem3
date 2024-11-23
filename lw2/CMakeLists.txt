cmake_minimum_required(VERSION 3.29)
project(PPOIS_lw2_sem3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -Wall -Wextra -Wpedantic")

include_directories(include)

add_library(RepairCompany SHARED
        src/carpenter.cc
        src/employee.cc
        src/technician.cc
        src/electrician.cc
        src/manager.cc
        src/plumber.cc
        src/receptionist.cc
        src/project_manager.cc
        src/finance_manager.cc
        src/supervisor.cc
        src/warehouse_manager.cc
        src/client.cc
        src/service_request.cc
        src/invoice.cc
        src/repair_company.cc
)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include(GoogleTest)

add_executable(technician_tests tests/technician_tests.cc)
target_link_libraries(technician_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(technician_tests)

add_executable(carpenter_tests tests/carpenter_tests.cc)
target_link_libraries(carpenter_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(carpenter_tests)

add_executable(electrician_tests tests/electrician_tests.cc)
target_link_libraries(electrician_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(electrician_tests)

add_executable(manager_tests tests/manager_tests.cc)
target_link_libraries(manager_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(manager_tests)

add_executable(plumber_tests tests/plumber_tests.cc)
target_link_libraries(plumber_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(plumber_tests)

add_executable(receptionist_tests tests/receptionist_tests.cc)
target_link_libraries(receptionist_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(receptionist_tests)

add_executable(project_manager_tests tests/project_manager_tests.cc)
target_link_libraries(project_manager_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(project_manager_tests)

add_executable(finance_manager_tests tests/finance_manager_tests.cc)
target_link_libraries(finance_manager_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(finance_manager_tests)

add_executable(supervisor_tests tests/supervisor_tests.cc)
target_link_libraries(supervisor_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(supervisor_tests)

add_executable(warehouse_manager_tests tests/warehouse_manager_tests.cc)
target_link_libraries(warehouse_manager_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(warehouse_manager_tests)

add_executable(client_tests tests/client_tests.cc)
target_link_libraries(client_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(client_tests)

add_executable(service_request_tests tests/service_request_tests.cc)
target_link_libraries(service_request_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(service_request_tests)

add_executable(invoice_tests tests/invoice_tests.cc)
target_link_libraries(invoice_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(invoice_tests)

add_executable(repair_company_tests tests/repair_company_tests.cc)
target_link_libraries(repair_company_tests RepairCompany GTest::GTest GTest::Main)
gtest_discover_tests(repair_company_tests)

