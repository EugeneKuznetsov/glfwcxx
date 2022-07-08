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
    if (default_window_hints_.resizable_ != hints.resizable_)
        glfwWindowHint(GLFW_RESIZABLE, hints.resizable_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.visible_ != hints.visible_)
        glfwWindowHint(GLFW_VISIBLE, hints.visible_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.decorated_ != hints.decorated_)
        glfwWindowHint(GLFW_DECORATED, hints.decorated_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.focused_ != hints.focused_)
        glfwWindowHint(GLFW_FOCUSED, hints.focused_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.auto_iconify_ != hints.auto_iconify_)
        glfwWindowHint(GLFW_AUTO_ICONIFY, hints.auto_iconify_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.floating_ != hints.floating_)
        glfwWindowHint(GLFW_FLOATING, hints.floating_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.opengl_profile_ != hints.opengl_profile_)
        glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int>(hints.opengl_profile_));

    if (default_window_hints_.context_version_ != hints.context_version_) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, hints.context_version_.major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, hints.context_version_.minor);
    }

    return std::unique_ptr<Window>{new Window{size, title}};
}

auto Window::make_context_current() -> void
{
    glfwMakeContextCurrent(window_->glfw_window());
    if (auto last_error = get_last_error(); Error::NO_ERROR != last_error.first)
        throw std::runtime_error("Failed to make context current: " + last_error.second);
}

auto Window::poll_events() -> void
{
    glfwPollEvents();
}

auto Window::swap_buffers() -> void
{
    glfwSwapBuffers(window_->glfw_window());
}

auto Window::should_close() const -> bool
{
    return 0 != glfwWindowShouldClose(window_->glfw_window());
}

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
