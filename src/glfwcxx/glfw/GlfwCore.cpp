#include "glfwcxx/GlfwCore.hpp"

#include <stdexcept>

#include <GLFW/glfw3.h>

namespace glfwcxx {

GlfwCore::GlfwCore()
{
    if (GLFW_FALSE == glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");
}

GlfwCore::~GlfwCore()
{
    glfwTerminate();
}

auto GlfwCore::init() -> GlfwCore&
{
    static GlfwCore glfw;
    return glfw;
}

}  // namespace glfwcxx
