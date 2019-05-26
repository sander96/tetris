cmake_minimum_required(VERSION 3.14)
project(tetris)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wnon-virtual-dtor -pedantic")

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})

add_executable(tetris src/main.cpp src/Application.cpp src/Application.h src/Game.cpp src/Game.h src/Playfield.cpp src/Playfield.h src/BlockType.h src/Piece.cpp src/Piece.h src/GameEvent.h src/RandomBag.cpp src/RandomBag.h)

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
