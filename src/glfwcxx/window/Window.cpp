#include "glfwcxx/Window.hpp"

namespace glfwcxx {

auto Window::create_window(const WindowSize& /*size*/, const std::string& /*title*/) -> std::unique_ptr<Window>
{
    return std::unique_ptr<Window>{new Window{}};
}

auto Window::create_window(const WindowSize& /*size*/, const std::string& /*title*/, const WindowHints& /*hints*/)
    -> std::unique_ptr<Window>
{
    return std::unique_ptr<Window>{new Window{}};
}

auto Window::make_context_current() -> void {}

}  // namespace glfwcxx
