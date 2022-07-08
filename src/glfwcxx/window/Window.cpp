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

    setup_string_window_hints(hints);

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

    if (default_window_hints_.stereo_ != hints.stereo_)
        glfwWindowHint(GLFW_STEREO, hints.stereo_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.srgb_capable_ != hints.srgb_capable_)
        glfwWindowHint(GLFW_SRGB_CAPABLE, hints.srgb_capable_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.doublebuffer_ != hints.doublebuffer_)
        glfwWindowHint(GLFW_DOUBLEBUFFER, hints.doublebuffer_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.opengl_forward_compat_ != hints.opengl_forward_compat_)
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, hints.opengl_forward_compat_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.opengl_debug_context_ != hints.opengl_debug_context_)
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, hints.opengl_debug_context_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.cocoa_retina_framebuffer_ != hints.cocoa_retina_framebuffer_)
        glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, hints.cocoa_retina_framebuffer_ ? GLFW_TRUE : GLFW_FALSE);

    if (default_window_hints_.cocoa_graphics_switching_ != hints.cocoa_graphics_switching_)
        glfwWindowHint(GLFW_COCOA_GRAPHICS_SWITCHING, hints.cocoa_graphics_switching_ ? GLFW_TRUE : GLFW_FALSE);
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

    if (default_window_hints_.accum_red_bits_ != hints.accum_red_bits_)
        glfwWindowHint(GLFW_ACCUM_RED_BITS, hints.accum_red_bits_);

    if (default_window_hints_.accum_green_bits_ != hints.accum_green_bits_)
        glfwWindowHint(GLFW_ACCUM_GREEN_BITS, hints.accum_green_bits_);

    if (default_window_hints_.accum_blue_bits_ != hints.accum_blue_bits_)
        glfwWindowHint(GLFW_ACCUM_BLUE_BITS, hints.accum_blue_bits_);

    if (default_window_hints_.accum_alpha_bits_ != hints.accum_alpha_bits_)
        glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, hints.accum_alpha_bits_);

    if (default_window_hints_.aux_buffers_ != hints.aux_buffers_)
        glfwWindowHint(GLFW_AUX_BUFFERS, hints.aux_buffers_);

    if (default_window_hints_.samples_ != hints.samples_)
        glfwWindowHint(GLFW_SAMPLES, hints.samples_);

    if (default_window_hints_.refresh_rate_ != hints.refresh_rate_)
        glfwWindowHint(GLFW_REFRESH_RATE, hints.refresh_rate_);
}

auto Window::setup_string_window_hints(const WindowHints& hints) -> void
{
    if (default_window_hints_.cocoa_frame_name_ != hints.cocoa_frame_name_)
        glfwWindowHintString(GLFW_COCOA_FRAME_NAME, hints.cocoa_frame_name_.c_str());

    if (default_window_hints_.x11_class_name_ != hints.x11_class_name_)
        glfwWindowHintString(GLFW_X11_CLASS_NAME, hints.x11_class_name_.c_str());

    if (default_window_hints_.x11_instance_name_ != hints.x11_instance_name_)
        glfwWindowHintString(GLFW_X11_INSTANCE_NAME, hints.x11_instance_name_.c_str());
}

auto Window::setup_preset_window_hints(const WindowHints& hints) -> void
{
    if (default_window_hints_.opengl_profile_ != hints.opengl_profile_)
        glfwWindowHint(GLFW_OPENGL_PROFILE, static_cast<int>(hints.opengl_profile_));

    if (default_window_hints_.client_api_ != hints.client_api_)
        glfwWindowHint(GLFW_CLIENT_API, static_cast<int>(hints.client_api_));

    if (default_window_hints_.context_creation_api_ != hints.context_creation_api_)
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, static_cast<int>(hints.context_creation_api_));

    if (default_window_hints_.context_robustness_ != hints.context_robustness_)
        glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, static_cast<int>(hints.context_robustness_));

    if (default_window_hints_.context_release_behavior_ != hints.context_release_behavior_)
        glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, static_cast<int>(hints.context_release_behavior_));
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
