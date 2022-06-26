#include "GLFW/glfw3.h"

auto glfwInit() -> int
{
    return glfwcxx::Stub::glfwInit;
}

auto glfwTerminate() -> void {}

namespace glfwcxx {

bool Stub::glfwInit{GLFW_FALSE};

}
