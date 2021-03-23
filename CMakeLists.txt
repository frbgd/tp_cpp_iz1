cmake_minimum_required(VERSION 3.12)
project(tp_c_iz1)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDART_REQURED ON)
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

set(SCHEDULE_LIB_SOURCE_FILES src/schedule.c src/schedule.h)
set(TEST_DATA_LIB_SOURCE_FILES src/test_data.c src/test_data.h)

add_library(schedule_lib STATIC ${SCHEDULE_LIB_SOURCE_FILES})
add_library(test_data_lib ${TEST_DATA_LIB_SOURCE_FILES})

add_executable(prog src/main.c)
target_link_libraries(prog schedule_lib)
target_link_libraries(prog test_data_lib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDART_REQURED ON)
set(CMAKE_CXX_FLAGS         "-Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

add_subdirectory(thirdparty/gtest)
add_executable(tests src/tests.cpp)
target_link_libraries(tests schedule_lib)
target_link_libraries(tests test_data_lib)
target_link_libraries(tests gtest ${CMAKE_THREAD_LIBS_INIT})
enable_testing()

add_test(gtests ./tests)