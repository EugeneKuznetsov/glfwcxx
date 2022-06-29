set(TARGET_NAME common)
set(SOURCES Common.cpp)
set(STUB_SOURCES CommonStub.cpp)

add_glfwcxx_target(NAME ${TARGET_NAME} SOURCES ${SOURCES} STUB_SOURCES ${STUB_SOURCES})
install_glfwcxx_target(NAME ${TARGET_NAME})
