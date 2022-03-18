cmake_minimum_required(VERSION 3.16)

#find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}" )

file(GLOB SOURCES *.cpp)

message("Enabled testing")
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include_directories(${GTEST_INCLUDE_DIR})

enable_testing()
message("Google C++ Testing Framework loaded")

add_executable(my_first_test tests.cpp ../src/utils.c ../src/food.c)
target_link_libraries(my_first_test gtest_main)
target_include_directories(my_first_test PRIVATE ..)

include(GoogleTest)
gtest_discover_tests(my_first_test)