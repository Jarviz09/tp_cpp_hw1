cmake_minimum_required(VERSION 3.16)
project(HW1)


set(CMAKE_C_STANDARD 99)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wpedantic -Wextra -Werror -fprofile-arcs -ftest-coverage -fPIC -O0")
SET(GCC_COVERAGE_LINK_FLAGS  "-lgcov")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
set(PROJECT_LIB_SOURCE_DIR project/src)
set(PROJECT_FOOD_LIB_NAME food_lib)
set(PROJECT_LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR})



set(SOURCES
        project/main.c
)



add_library(${PROJECT_FOOD_LIB_NAME} project/src/food.c project/src/utils.c)
target_include_directories(${PROJECT_FOOD_LIB_NAME} PUBLIC ${PROJECT_LIB_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_FOOD_LIB_NAME})
target_include_directories(HW1 PUBLIC project/include)


add_subdirectory(tests)