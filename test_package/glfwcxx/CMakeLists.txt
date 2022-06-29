set(CURRENT_TARGET glfwcxxapp)

add_executable(${CURRENT_TARGET} main.cpp)
target_link_libraries(${CURRENT_TARGET} PRIVATE glfwcxx::core glfwcxx::window)
