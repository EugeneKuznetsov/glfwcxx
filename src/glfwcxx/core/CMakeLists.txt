set(SOURCES Core.cpp CoreInitHints.cpp)
set(STUB_SOURCES CoreStub.cpp)

add_glfwcxx_target(
    NAME
    core
    SOURCES
    ${SOURCES}
    STUB_SOURCES
    ${STUB_SOURCES}
    EXTRA_PRIVATE_LIBS
    glfwcxx::common
    EXTRA_PRIVATE_STUB_LIBS
    glfwcxx::common-stub)
install_glfwcxx_target(NAME core)
