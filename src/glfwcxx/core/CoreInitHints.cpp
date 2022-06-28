#include "glfwcxx/CoreInitHints.hpp"

namespace glfwcxx {

auto CoreInitHints::with_joystick_hat_buttons() -> CoreInitHints&
{
    joystick_hat_buttons = true;
    return *this;
}

auto CoreInitHints::with_cocoa_chdir_resources() -> CoreInitHints&
{
    cocoa_chdir_resources = true;
    return *this;
}

auto CoreInitHints::with_cocoa_menubar() -> CoreInitHints&
{
    cocoa_menubar = true;
    return *this;
}

}  // namespace glfwcxx
