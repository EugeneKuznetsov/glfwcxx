#include "glfwcxx/Core.hpp"

#include <stdexcept>

#include <GLFW/glfw3.h>

namespace glfwcxx {

Core::Core()
{
    if (GLFW_FALSE == glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");
}

Core::~Core()
{
    glfwTerminate();
}

auto Core::init() -> std::unique_ptr<Core>
{
    return std::unique_ptr<Core>{new Core{}};
}

}  // namespace glfwcxx
