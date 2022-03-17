cmake_minimum_required(VERSION 3.16)
project(HW1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Werror -Wextra -Wpedantic -Wall")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})

set(SOURCES
        main.c
        src/food.c
        src/utils.c)


add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(HW1 PUBLIC /include)

add_subdirectory(tests)