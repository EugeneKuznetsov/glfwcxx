#include <cstdlib>
#include <stdexcept>

#include <glfwcxx/Core.hpp>
#include <glfwcxx/CoreInitHints.hpp>
#include <glfwcxx/CoreStub.hpp>
#include <glfwcxx/Window.hpp>
#include <glfwcxx/WindowHelper.hpp>
#include <glfwcxx/KeyboardHelper.hpp>

auto main() -> int
{
    glfwcxx::CoreStub::init_failure();
    try {
        auto glfw = glfwcxx::Core::init(glfwcxx::CoreInitHints{}.with_joystick_hat_buttons());
    }
    catch (const std::runtime_error&) {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
