#include <cstdlib>

#include <glfwcxx/GlfwCore.hpp>
#include <GLFW/glfw3.h>

auto main() -> int
{
    glfwcxx::Stub::glfwInit = GLFW_TRUE;
    glfwcxx::GlfwCore::init();
    return EXIT_SUCCESS;
}
