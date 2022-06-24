set(CURRENT_TARGET stub)
set(CURRENT_TARGET_ALIAS stub::glfw)

add_library(${CURRENT_TARGET} INTERFACE)
target_include_directories(${CURRENT_TARGET}
                           INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)

add_library(${CURRENT_TARGET_ALIAS} ALIAS ${CURRENT_TARGET})
