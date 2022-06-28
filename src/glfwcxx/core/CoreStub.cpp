#include "glfwcxx/CoreStub.hpp"

#include <GLFW/glfw3.h>

namespace glfwcxx {

int CoreStub::init_return_value_ = GLFW_TRUE;

auto CoreStub::init_failure() -> void
{
    init_return_value_ = GLFW_FALSE;
}

auto CoreStub::init_success() -> void
{
    init_return_value_ = GLFW_TRUE;
}

}  // namespace glfwcxx

auto glfwInit() -> int
{
    return glfwcxx::CoreStub::init_return_value();
}

auto glfwTerminate() -> void {}
