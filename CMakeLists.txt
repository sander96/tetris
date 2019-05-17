cmake_minimum_required(VERSION 3.14)
project(tetris)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic")

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})

add_executable(tetris main.cpp)

find_library(SFML_AUDIO sfml-audio "${PROJECT_SOURCE_DIR}/lib")
find_library(SFML_GRAPHICS sfml-graphics "${PROJECT_SOURCE_DIR}/lib")
find_library(SFML_NETOWRK sfml-network "${PROJECT_SOURCE_DIR}/lib")
find_library(SFML_SYSTEM sfml-system "${PROJECT_SOURCE_DIR}/lib")
find_library(SFML_WINDOW sfml-window "${PROJECT_SOURCE_DIR}/lib")

target_link_libraries(tetris "${SFML_AUDIO}")
target_link_libraries(tetris "${SFML_GRAPHICS}")
target_link_libraries(tetris "${SFML_NETOWRK}")
target_link_libraries(tetris "${SFML_SYSTEM}")
target_link_libraries(tetris "${SFML_WINDOW}")
