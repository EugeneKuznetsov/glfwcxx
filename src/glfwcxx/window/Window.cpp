#include "glfwcxx/Window.hpp"

#include <stdexcept>

#include <GLFW/glfw3.h>

#include "glfwcxx/Common.hpp"
#include "glfwcxx/KeyboardHelper.hpp"
#include "glfwcxx/WindowHelper.hpp"

namespace glfwcxx {

class Window::WindowDetails {
public:
    WindowDetails(const WindowSize& size, const std::string& title);
    ~WindowDetails();

public:
    auto keyboard_input(const keyboard_callback_t& callback) -> void;

public:
    auto glfw_window() const -> GLFWwindow*;

public:
    static const WindowHints default_window_hints_;

private:
#ifdef __linux__
    using Deleter = void (*)(GLFWwindow*);
#else
    using Deleter = void(__cdecl&)(GLFWwindow*);
#endif
    std::unique_ptr<GLFWwindow, Deleter> glfw_window_;
    keyboard_callback_t keyboard_input_;
};

const WindowHints Window::WindowDetails::default_window_hints_ = {};

Window::Window(const WindowSize& size, const std::string& title)
    : window_{std::make_unique<WindowDetails>(size, title)}
{
}

Window::~Window() = default;

auto Window::create_window(const WindowSize& size, const std::string& title) -> std::unique_ptr<Window>
{
    return create_window(size, title, WindowDetails::default_window_hints_);
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

auto Window::close() -> void
{
    glfwSetWindowShouldClose(window_->glfw_window(), GLFW_TRUE);
}

auto Window::should_close() const -> bool
{
    return GLFW_FALSE != glfwWindowShouldClose(window_->glfw_window());
}

auto Window::window_size() const -> WindowSize
{
    return {0, 0};
}

auto Window::frame_buffer_size() const -> FrameBufferSize
{
    return {0, 0};
}

auto Window::window_content_scale() const -> WindowContentScale
{
    return {0.0f, 0.0f};
}

auto Window::keyboard_input(const keyboard_callback_t& callback) -> void
{
    window_->keyboard_input(callback);
}

auto Window::window_size(const window_size_callback_t& /*callback*/) -> void {}

auto Window::frame_buffer_size(const frame_buffer_size_callback_t& /*callback*/) -> void {}

auto Window::window_content_scale(const window_content_scale_callback_t& /*callback*/) -> void {}

auto Window::setup_boolean_window_hints(const WindowHints& hints) -> void
{
    using namespace glfwcxx::helpers;

    if (WindowDetails::default_window_hints_.resizable_ != hints.resizable_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::resizable), hints.resizable_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.visible_ != hints.visible_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::visible), hints.visible_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.decorated_ != hints.decorated_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::decorated), hints.decorated_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.focused_ != hints.focused_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::focused), hints.focused_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.auto_iconify_ != hints.auto_iconify_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::auto_iconify), hints.auto_iconify_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.floating_ != hints.floating_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::floating), hints.floating_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.maximized_ != hints.maximized_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::maximized), hints.maximized_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.center_cursor_ != hints.center_cursor_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::center_cursor), hints.center_cursor_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.transparent_framebuffer_ != hints.transparent_framebuffer_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::transparent_framebuffer), hints.transparent_framebuffer_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.focus_on_show_ != hints.focus_on_show_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::focus_on_show), hints.focus_on_show_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.scale_to_monitor_ != hints.scale_to_monitor_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::scale_to_monitor), hints.scale_to_monitor_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.stereo_ != hints.stereo_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::stereo), hints.stereo_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.srgb_capable_ != hints.srgb_capable_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::srgb_capable), hints.srgb_capable_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.doublebuffer_ != hints.doublebuffer_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::doublebuffer), hints.doublebuffer_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.opengl_forward_compat_ != hints.opengl_forward_compat_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::opengl_forward_compat), hints.opengl_forward_compat_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.opengl_debug_context_ != hints.opengl_debug_context_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::opengl_debug_context), hints.opengl_debug_context_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.cocoa_retina_framebuffer_ != hints.cocoa_retina_framebuffer_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::cocoa_retina_framebuffer), hints.cocoa_retina_framebuffer_ ? GLFW_TRUE : GLFW_FALSE);

    if (WindowDetails::default_window_hints_.cocoa_graphics_switching_ != hints.cocoa_graphics_switching_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::cocoa_graphics_switching), hints.cocoa_graphics_switching_ ? GLFW_TRUE : GLFW_FALSE);
}

auto Window::setup_numeric_window_hints(const WindowHints& hints) -> void
{
    using namespace glfwcxx::helpers;

    if (WindowDetails::default_window_hints_.context_version_ != hints.context_version_) {
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::context_version_major), hints.context_version_.major);
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::context_version_minor), hints.context_version_.minor);
    }

    if (WindowDetails::default_window_hints_.red_bits_ != hints.red_bits_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::red_bits), hints.red_bits_);

    if (WindowDetails::default_window_hints_.green_bits_ != hints.green_bits_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::green_bits), hints.green_bits_);

    if (WindowDetails::default_window_hints_.blue_bits_ != hints.blue_bits_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::blue_bits), hints.blue_bits_);

    if (WindowDetails::default_window_hints_.alpha_bits_ != hints.alpha_bits_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::alpha_bits), hints.alpha_bits_);

    if (WindowDetails::default_window_hints_.depth_bits_ != hints.depth_bits_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::depth_bits), hints.depth_bits_);

    if (WindowDetails::default_window_hints_.stencil_bits_ != hints.stencil_bits_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::stencil_bits), hints.stencil_bits_);

    if (WindowDetails::default_window_hints_.accum_red_bits_ != hints.accum_red_bits_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::accum_red_bits), hints.accum_red_bits_);

    if (WindowDetails::default_window_hints_.accum_green_bits_ != hints.accum_green_bits_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::accum_green_bits), hints.accum_green_bits_);

    if (WindowDetails::default_window_hints_.accum_blue_bits_ != hints.accum_blue_bits_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::accum_blue_bits), hints.accum_blue_bits_);

    if (WindowDetails::default_window_hints_.accum_alpha_bits_ != hints.accum_alpha_bits_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::accum_alpha_bits), hints.accum_alpha_bits_);

    if (WindowDetails::default_window_hints_.aux_buffers_ != hints.aux_buffers_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::aux_buffers), hints.aux_buffers_);

    if (WindowDetails::default_window_hints_.samples_ != hints.samples_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::samples), hints.samples_);

    if (WindowDetails::default_window_hints_.refresh_rate_ != hints.refresh_rate_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::refresh_rate), hints.refresh_rate_);
}

auto Window::setup_string_window_hints(const WindowHints& hints) -> void
{
    using namespace glfwcxx::helpers;

    if (WindowDetails::default_window_hints_.cocoa_frame_name_ != hints.cocoa_frame_name_)
        glfwWindowHintString(glfw_hint_key(WindowHintsKeys::cocoa_frame_name), hints.cocoa_frame_name_.c_str());

    if (WindowDetails::default_window_hints_.x11_class_name_ != hints.x11_class_name_)
        glfwWindowHintString(glfw_hint_key(WindowHintsKeys::x11_class_name), hints.x11_class_name_.c_str());

    if (WindowDetails::default_window_hints_.x11_instance_name_ != hints.x11_instance_name_)
        glfwWindowHintString(glfw_hint_key(WindowHintsKeys::x11_instance_name), hints.x11_instance_name_.c_str());
}

auto Window::setup_preset_window_hints(const WindowHints& hints) -> void
{
    using namespace glfwcxx::helpers;

    if (WindowDetails::default_window_hints_.opengl_profile_ != hints.opengl_profile_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::opengl_profile), glfw_hint_value(hints.opengl_profile_));

    if (WindowDetails::default_window_hints_.client_api_ != hints.client_api_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::client_api), glfw_hint_value(hints.client_api_));

    if (WindowDetails::default_window_hints_.context_creation_api_ != hints.context_creation_api_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::context_creation_api), glfw_hint_value(hints.context_creation_api_));

    if (WindowDetails::default_window_hints_.context_robustness_ != hints.context_robustness_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::context_robustness), glfw_hint_value(hints.context_robustness_));

    if (WindowDetails::default_window_hints_.context_release_behavior_ != hints.context_release_behavior_)
        glfwWindowHint(glfw_hint_key(WindowHintsKeys::context_release_behavior), glfw_hint_value(hints.context_release_behavior_));
}

Window::WindowDetails::WindowDetails(const WindowSize& size, const std::string& title)
    : glfw_window_{nullptr, glfwDestroyWindow}
    , keyboard_input_{nullptr}
{
    glfw_window_.reset(glfwCreateWindow(size.width, size.height, title.c_str(), nullptr, nullptr));
    if (nullptr == glfw_window_)
        throw std::runtime_error("Failed to create GLFW window: " + get_last_error().second);
}

Window::WindowDetails::~WindowDetails()
{
    glfwSetWindowUserPointer(glfw_window(), nullptr);
    glfwSetKeyCallback(glfw_window(), nullptr);
}

auto Window::WindowDetails::keyboard_input(const keyboard_callback_t& callback) -> void
{
    keyboard_input_ = callback;

    glfwSetWindowUserPointer(glfw_window(), this);
    glfwSetKeyCallback(glfw_window(), [](GLFWwindow* window, int key, int, int action, int mods) -> void {
        auto self = static_cast<Window::WindowDetails*>(glfwGetWindowUserPointer(window));
        using namespace glfwcxx::input;
        std::set<KeyboardKeyModifier> modifiers;
        const auto insert_modifier_if = [&modifiers, &mods](auto glfw_modifier, auto glfwcxx_modifier) -> void {
            if (glfw_modifier & mods)
                modifiers.insert(glfwcxx_modifier);
        };
        insert_modifier_if(GLFW_MOD_SHIFT, KeyboardKeyModifier::mod_shift);
        insert_modifier_if(GLFW_MOD_CONTROL, KeyboardKeyModifier::mod_control);
        insert_modifier_if(GLFW_MOD_ALT, KeyboardKeyModifier::mod_alt);
        insert_modifier_if(GLFW_MOD_SUPER, KeyboardKeyModifier::mod_super);
        insert_modifier_if(GLFW_MOD_CAPS_LOCK, KeyboardKeyModifier::mod_caps_lock);
        insert_modifier_if(GLFW_MOD_NUM_LOCK, KeyboardKeyModifier::mod_num_lock);
        self->keyboard_input_(glfwcxx::helpers::glfwcxx_keyboard_key(key), glfwcxx::helpers::glfwcxx_keyboard_action(action), modifiers);
    });
}

auto Window::WindowDetails::glfw_window() const -> GLFWwindow*
{
    return glfw_window_.get();
}

}  // namespace glfwcxx
