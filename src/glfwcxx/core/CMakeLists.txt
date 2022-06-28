set(SOURCES Core.cpp CoreInitHints.cpp)
set(STUB_SOURCES CoreStub.cpp)

add_glfwcxx_target(NAME core SOURCES ${SOURCES} STUB_SOURCES ${STUB_SOURCES})
install_glfwcxx_target(NAME core)
