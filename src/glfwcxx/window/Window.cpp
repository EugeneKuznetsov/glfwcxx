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
    setup_boolean_window_hints(hints);

    setup_numeric_window_hints(hints);

    setup_preset_window_hints(hints);

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

auto Window::setup_boolean_window_hints(const WindowHints& hints) -> void
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

    if (default_window_hints_.maximized_ != hints.maximized_)
        glfwWindowHint(GLFW_MAXIMIZED, hints.maximized_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.center_cursor_ != hints.center_cursor_)
        glfwWindowHint(GLFW_CENTER_CURSOR, hints.center_cursor_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.transparent_framebuffer_ != hints.transparent_framebuffer_)
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, hints.transparent_framebuffer_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.focus_on_show_ != hints.focus_on_show_)
        glfwWindowHint(GLFW_FOCUS_ON_SHOW, hints.focus_on_show_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.scale_to_monitor_ != hints.scale_to_monitor_)
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, hints.scale_to_monitor_ ? GLFW_TRUE : GLFW_FALSE);
}

auto Window::setup_numeric_window_hints(const WindowHints& hints) -> void
{
    if (default_window_hints_.context_version_ != hints.context_version_) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, hints.context_version_.major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, hints.context_version_.minor);
    }

    if (default_window_hints_.red_bits_ != hints.red_bits_)
        glfwWindowHint(GLFW_RED_BITS, hints.red_bits_);

    if (default_window_hints_.green_bits_ != hints.green_bits_)
        glfwWindowHint(GLFW_GREEN_BITS, hints.green_bits_);

    if (default_window_hints_.blue_bits_ != hints.blue_bits_)
        glfwWindowHint(GLFW_BLUE_BITS, hints.blue_bits_);

    if (default_window_hints_.alpha_bits_ != hints.alpha_bits_)
        glfwWindowHint(GLFW_ALPHA_BITS, hints.alpha_bits_);

    if (default_window_hints_.depth_bits_ != hints.depth_bits_)
        glfwWindowHint(GLFW_DEPTH_BITS, hints.depth_bits_);

    if (default_window_hints_.stencil_bits_ != hints.stencil_bits_)
        glfwWindowHint(GLFW_STENCIL_BITS, hints.stencil_bits_);
}

auto Window::setup_preset_window_hints(const WindowHints& hints) -> void
{
    if (default_window_hints_.opengl_profile_ != hints.opengl_profile_)
        glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int>(hints.opengl_profile_));
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
