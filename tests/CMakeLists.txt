cmake_minimum_required(VERSION 3.16)

find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES *.cpp)

message("Enabled testing")
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
message("Google C++ Testing Framework loaded")

add_executable(my_first_test tests.cpp)
target_link_libraries(my_first_test gtest_main)

include(GoogleTest)
gtest_discover_tests(my_first_test)