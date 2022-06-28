set(CURRENT_TARGET glfwstub)

add_library(${CURRENT_TARGET} INTERFACE)
target_include_directories(${CURRENT_TARGET}
                           INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)
