cmake_minimum_required(VERSION 3.10)
project(design_pattern)

set(SOURCE
    primer_program/maze_game.cc
)
add_executable(primer_program ${SOURCE})
target_include_directories(primer_program
    PRIVATE
        ${PROJECT_SOURCE_DIR}/primer_program
)

set(SOURCE
    abstract_factory/abstract_factory.cc
    abstract_factory/maze_game.cc
)
add_executable(abstract_factory ${SOURCE})
target_include_directories(abstract_factory
    PRIVATE
        ${PROJECT_SOURCE_DIR}/abstract_factory
)

set(SOURCE
    factory_method/maze_game.cc
)
add_executable(factory_method ${SOURCE})
target_include_directories(factory_method
    PRIVATE
        ${PROJECT_SOURCE_DIR}/factory_method
)
