cmake_minimum_required(VERSION 3.16)
project(tp_c_iz1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "--coverage")

set(SCHEDULE_LIB_SOURCE_FILES src/schedule.c src/schedule.h)
set(TEST_DATA_LIB_SOURCE_FILES src/test_data.c src/test_data.h)

add_library(schedule_lib STATIC ${SCHEDULE_LIB_SOURCE_FILES})
add_library(test_data_lib ${TEST_DATA_LIB_SOURCE_FILES})

add_executable(prog src/main.c)
target_link_libraries(prog schedule_lib)
target_link_libraries(prog test_data_lib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS         "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
message(${GTEST_LIBRARIES})
add_executable(tests src/tests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} -lpthread)
target_link_libraries(tests schedule_lib)
target_link_libraries(tests test_data_lib)
enable_testing()

add_test(gtests ./tests)