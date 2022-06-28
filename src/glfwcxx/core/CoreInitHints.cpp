#include "glfwcxx/CoreInitHints.hpp"

namespace glfwcxx {

auto CoreInitHints::with_joystick_hat_buttons() -> CoreInitHints&
{
    return *this;
}

auto CoreInitHints::with_cocoa_chdir_resources() -> CoreInitHints&
{
    return *this;
}

auto CoreInitHints::with_cocoa_menubar() -> CoreInitHints&
{
    return *this;
}

}  // namespace glfwcxx
