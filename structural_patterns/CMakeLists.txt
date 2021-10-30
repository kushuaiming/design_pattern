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

set(SOURCE
    bridge/bridge.cc
    bridge/common.cc
)
add_executable(bridge ${SOURCE})
target_include_directories(bridge
    PRIVATE
        ${PROJECT_SOURCE_DIR}/bridge
)
