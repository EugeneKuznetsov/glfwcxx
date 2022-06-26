set(CURRENT_TARGET glfwcore)
set(CURRENT_STUB_TARGET ${CURRENT_TARGET}-stub)

set(SOURCES GlfwCore.cpp)

add_library(${CURRENT_TARGET} STATIC ${SOURCES})
target_include_directories(${CURRENT_TARGET}
                           PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)
target_link_libraries(${CURRENT_TARGET} PRIVATE $<BUILD_INTERFACE:glfw::glfw>)

add_library(${CURRENT_STUB_TARGET} STATIC ${SOURCES})
target_include_directories(${CURRENT_STUB_TARGET}
                           PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)
target_link_libraries(${CURRENT_STUB_TARGET} PUBLIC $<BUILD_INTERFACE:stub::glfw>)
