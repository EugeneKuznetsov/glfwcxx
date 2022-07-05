set(TARGET_NAME core)

add_glfwcxx_target(
    GLFWCXX_TARGET_NAME
    ${TARGET_NAME}
    TARGET_SOURCES
    Core.cpp
    CoreInitHints.cpp
    PRIVATE_DEPENDENCY_TARGETS
    glfw::glfw
    glfwcxx::common)
add_glfwcxx_stub_target(
    GLFWCXX_TARGET_NAME
    ${TARGET_NAME}
    TARGET_SOURCES
    CoreStub.cpp
    PRIVATE_DEPENDENCY_TARGETS
    glfwstub
    glfwcxx::common-stub)

install_glfwcxx_target(GLFWCXX_TARGET_NAME ${TARGET_NAME})
install_glfwcxx_stub_target(GLFWCXX_TARGET_NAME ${TARGET_NAME})
