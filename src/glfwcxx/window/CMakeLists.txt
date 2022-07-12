set(TARGET_NAME window)
set(HELPER_API ${CMAKE_CURRENT_LIST_DIR}/include/helper)

add_glfwcxx_target(
    GLFWCXX_TARGET_NAME
    ${TARGET_NAME}
    TARGET_SOURCES
    Window.cpp
    WindowHints.cpp
    WindowHelper.cpp
    KeyboardHelper.cpp
    PRIVATE_DEPENDENCY_TARGETS
    glfw::glfw
    glfwcxx::common
    PRIVATE_INCLUDE_DIRECTORIES
    ${HELPER_API})
add_glfwcxx_stub_target(
    GLFWCXX_TARGET_NAME
    ${TARGET_NAME}
    TARGET_SOURCES
    WindowStub.cpp
    PRIVATE_DEPENDENCY_TARGETS
    glfwstub
    glfwcxx::common-stub
    PUBLIC_INCLUDE_DIRECTORIES
    ${HELPER_API})

install_glfwcxx_target(GLFWCXX_TARGET_NAME ${TARGET_NAME})
install_glfwcxx_stub_target(GLFWCXX_TARGET_NAME ${TARGET_NAME} EXTRA_INSTALL_DIRECTORIES
                            ${HELPER_API}/glfwcxx)
