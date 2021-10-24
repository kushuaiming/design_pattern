project(structural_patterns)

set(SOURCE
    adapter/class_adapter.cc
    adapter/common.cc
)
add_executable(adapter ${SOURCE})
target_include_directories(adapter
    PRIVATE
        ${PROJECT_SOURCE_DIR}/adapter
)
