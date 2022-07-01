#include "glfwcxx/Window.hpp"

#include <stdexcept>

#include <GLFW/glfw3.h>

#include "glfwcxx/Common.hpp"

namespace glfwcxx {

class Window::WindowDetails {
public:
    WindowDetails(const WindowSize& size, const std::string& title);

public:
    auto glfw_window() const -> GLFWwindow*;

private:
#ifdef __linux__
    using Deleter = void (*)(GLFWwindow*);
#else
    using Deleter = void(__cdecl&)(GLFWwindow*);
#endif
    std::unique_ptr<GLFWwindow, Deleter> glfw_window_;
};

const WindowHints Window::default_window_hints_ = {};

Window::Window(const WindowSize& size, const std::string& title)
    : window_{std::make_unique<WindowDetails>(size, title)}
{
}

Window::~Window() = default;

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
    glfwMakeContextCurrent(window_->glfw_window());
    if (auto last_error = get_last_error(); Error::NO_ERROR != last_error.first)
        throw std::runtime_error("Failed to make context current: " + last_error.second);
}

auto Window::poll_events() -> void {}

auto Window::swap_buffers() -> void {}

Window::WindowDetails::WindowDetails(const WindowSize& size, const std::string& title)
    : glfw_window_{nullptr, glfwDestroyWindow}
{
    glfw_window_.reset(glfwCreateWindow(size.width, size.height, title.c_str(), nullptr, nullptr));
    if (nullptr == glfw_window_)
        throw std::runtime_error("Failed to create GLFW window: " + get_last_error().second);
}

auto Window::WindowDetails::glfw_window() const -> GLFWwindow*
{
    return glfw_window_.get();
}

}  // namespace glfwcxx
