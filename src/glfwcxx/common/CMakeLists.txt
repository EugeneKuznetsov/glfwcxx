set(TARGET_NAME common)

add_glfwcxx_target(GLFWCXX_TARGET_NAME ${TARGET_NAME} TARGET_SOURCES Common.cpp
                   PRIVATE_DEPENDENCY_TARGETS glfw::glfw)
add_glfwcxx_stub_target(GLFWCXX_TARGET_NAME ${TARGET_NAME} TARGET_SOURCES CommonStub.cpp
                        PRIVATE_DEPENDENCY_TARGETS glfwstub)

install_glfwcxx_target(GLFWCXX_TARGET_NAME ${TARGET_NAME})
install_glfwcxx_stub_target(GLFWCXX_TARGET_NAME ${TARGET_NAME})
