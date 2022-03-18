cmake_minimum_required(VERSION 3.16)
project(HW1)


set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror -fprofile-arcs -ftest-coverage -fPIC -O0")
set(PROJECT_LIB_SOURCE_DIR /src)
set(PROJECT_FOOD_LIB_NAME food_lib)
set(PROJECT_LIB_INCLUDE_DIR ${PROJECT_SOURCE_DIR})

set(SOURCES
        main.c
)


add_library(${PROJECT_FOOD_LIB_NAME} src/food.c src/utils.c)
target_include_directories(${PROJECT_FOOD_LIB_NAME} PUBLIC ${PROJECT_LIB_INCLUDE_DIR})
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_FOOD_LIB_NAME})
target_include_directories(HW1 PUBLIC /include)


add_subdirectory(tests)