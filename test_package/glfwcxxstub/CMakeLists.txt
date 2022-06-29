set(CURRENT_TARGET glfwcxxstubapp)

add_executable(${CURRENT_TARGET} main.cpp)
target_link_libraries(${CURRENT_TARGET} PRIVATE glfwcxx::core-stub glfwcxx::window-stub)
