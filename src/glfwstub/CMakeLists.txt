set(CURRENT_TARGET stub)
set(CURRENT_TARGET_ALIAS stub::glfw)

add_library(${CURRENT_TARGET} STATIC glfw3.cpp)
target_include_directories(${CURRENT_TARGET}
                           PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)

add_library(${CURRENT_TARGET_ALIAS} ALIAS ${CURRENT_TARGET})
