set(TARGET_NAME window)

add_glfwcxx_target(
    GLFWCXX_TARGET_NAME
    ${TARGET_NAME}
    TARGET_SOURCES
    Window.cpp
    WindowHints.cpp
    PRIVATE_DEPENDENCY_TARGETS
    glfw::glfw
    glfwcxx::common)
add_glfwcxx_stub_target(
    GLFWCXX_TARGET_NAME
    ${TARGET_NAME}
    TARGET_SOURCES
    WindowStub.cpp
    PRIVATE_DEPENDENCY_TARGETS
    glfwstub
    glfwcxx::common-stub)

install_glfwcxx_target(GLFWCXX_TARGET_NAME ${TARGET_NAME})
install_glfwcxx_stub_target(GLFWCXX_TARGET_NAME ${TARGET_NAME})
