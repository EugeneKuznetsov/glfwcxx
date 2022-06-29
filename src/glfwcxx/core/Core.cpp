#include "glfwcxx/Core.hpp"

#include <stdexcept>

#include <GLFW/glfw3.h>

#include "glfwcxx/Common.hpp"
#include "glfwcxx/CoreInitHints.hpp"

namespace glfwcxx {

Core::Core()
{
    using namespace std::string_literals;

    if (GLFW_FALSE == glfwInit())
        throw std::runtime_error("Failed to initialize GLFW: "s + get_last_error().second);
}

Core::~Core()
{
    glfwTerminate();
}

auto Core::init() -> std::unique_ptr<Core>
{
    return std::unique_ptr<Core>{new Core{}};
}

auto Core::init(const CoreInitHints& hints) -> std::unique_ptr<Core>
{
    if (hints.joystick_hat_buttons)
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_TRUE);
    if (hints.cocoa_chdir_resources)
        glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, GLFW_TRUE);
    if (hints.cocoa_menubar)
        glfwInitHint(GLFW_COCOA_MENUBAR, GLFW_TRUE);
    return init();
}

}  // namespace glfwcxx
