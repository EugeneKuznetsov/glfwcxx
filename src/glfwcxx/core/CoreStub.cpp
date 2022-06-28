#include "glfwcxx/CoreStub.hpp"

#include <GLFW/glfw3.h>

auto glfwInit() -> int
{
    return glfwcxx::CoreStub::init_return_value_;
}

auto glfwTerminate() -> void {}

auto glfwInitHint(int hint, int value) -> void
{
    glfwcxx::CoreStub::init_hints_[hint] = value;
}

namespace glfwcxx {

int CoreStub::init_return_value_ = GLFW_TRUE;
init_hints_map CoreStub::init_hints_ = {};

auto CoreStub::reset() -> void
{
    init_return_value_ = GLFW_TRUE;
    init_hints_.clear();
}

auto CoreStub::init_failure() -> void
{
    init_return_value_ = GLFW_FALSE;
}

auto CoreStub::init_success() -> void
{
    init_return_value_ = GLFW_TRUE;
}

auto CoreStub::was_inited_with_joystick_hat_buttons(const int and_the_value_was /*= GLFW_TRUE*/) -> bool
{
    if (init_hints_.cend() == init_hints_.find(GLFW_JOYSTICK_HAT_BUTTONS))
        return false;
    return init_hints_[GLFW_JOYSTICK_HAT_BUTTONS] == and_the_value_was;
}

auto CoreStub::was_inited_with_cocoa_chdir_resources(const int and_the_value_was /*= GLFW_TRUE*/) -> bool
{
    if (init_hints_.cend() == init_hints_.find(GLFW_COCOA_CHDIR_RESOURCES))
        return false;
    return init_hints_[GLFW_COCOA_CHDIR_RESOURCES] == and_the_value_was;
}

auto CoreStub::was_inited_with_cocoa_menubar(const int and_the_value_was /*= GLFW_TRUE*/) -> bool
{
    if (init_hints_.cend() == init_hints_.find(GLFW_COCOA_MENUBAR))
        return false;
    return init_hints_[GLFW_COCOA_MENUBAR] == and_the_value_was;
}

}  // namespace glfwcxx
