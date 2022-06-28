#include "glfwcxx/Core.hpp"

#include <stdexcept>

#include <GLFW/glfw3.h>

#include "glfwcxx/CoreInitHints.hpp"

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

auto Core::init(const CoreInitHints& /*hints*/) -> std::unique_ptr<Core>
{
    return init();
}

}  // namespace glfwcxx
