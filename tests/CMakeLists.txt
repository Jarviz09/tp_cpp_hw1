cmake_minimum_required(VERSION 3.16)

#find_package(GTest REQUIRED)
set(CMAKE_CXX_STANDARD 17)
SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage --coverage")
SET(GCC_COVERAGE_LINK_FLAGS  "-lgcov")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
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

file(GLOB TestsSRC "tests/*.cpp")

add_executable(my_first_test tests.cpp ../project/src/utils.c ../project/src/food.c)
target_link_libraries(my_first_test gtest_main)
target_include_directories(my_first_test PRIVATE ../project)

include(GoogleTest)
gtest_discover_tests(my_first_test)