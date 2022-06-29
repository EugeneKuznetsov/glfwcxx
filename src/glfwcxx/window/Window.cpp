#include "glfwcxx/Window.hpp"

#include <stdexcept>

#include <GLFW/glfw3.h>

#include <glfwcxx/Common.hpp>

namespace glfwcxx {

const WindowHints Window::default_window_hints_ = {};

Window::Window(const WindowSize& size, const std::string& title)
    : window_{nullptr, glfwDestroyWindow}
{
    window_.reset(glfwCreateWindow(size.width, size.height, title.c_str(), nullptr, nullptr));
    if (nullptr == window_)
        throw std::runtime_error("Failed to create GLFW window: " + get_last_error().second);
}

auto Window::create_window(const WindowSize& size, const std::string& title) -> std::unique_ptr<Window>
{
    return create_window(size, title, default_window_hints_);
}

auto Window::create_window(const WindowSize& size, const std::string& title, const WindowHints& hints) -> std::unique_ptr<Window>
{
    if (default_window_hints_.profile != hints.profile)
        glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int>(hints.profile));

    if (default_window_hints_.version != hints.version) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, hints.version.major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, hints.version.minor);
    }

    return std::unique_ptr<Window>{new Window{size, title}};
}

auto Window::make_context_current() -> void
{
    glfwMakeContextCurrent(window_.get());
    if (auto last_error = get_last_error(); Error::NO_ERROR != last_error.first)
        throw std::runtime_error("Failed to make context current: " + last_error.second);
}

}  // namespace glfwcxx
