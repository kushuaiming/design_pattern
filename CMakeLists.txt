cmake_minimum_required(VERSION 3.10)
project(design_pattern)

set(SOURCE
    creational_patterns/abstract_factory.cc
    creational_patterns/maze_game.cc
)

add_executable(design_pattern ${SOURCE})

target_include_directories(design_pattern
    PRIVATE
        ${PROJECT_SOURCE_DIR}/creational_patterns
)
