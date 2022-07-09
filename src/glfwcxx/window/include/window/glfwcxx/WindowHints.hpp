#pragma once

#include <string>

namespace glfwcxx {

static constexpr int DONT_CARE = -1;

enum class WindowHintsKeys {
    RESIZABLE,
    VISIBLE,
    DECORATED,
    FOCUSED,
    AUTO_ICONIFY,
    FLOATING,
    MAXIMIZED,
    CENTER_CURSOR,
    TRANSPARENT_FRAMEBUFFER,
    FOCUS_ON_SHOW,
    SCALE_TO_MONITOR,
    STEREO,
    SRGB_CAPABLE,
    DOUBLEBUFFER,
    OPENGL_FORWARD_COMPAT,
    OPENGL_DEBUG_CONTEXT,
    COCOA_RETINA_FRAMEBUFFER,
    COCOA_GRAPHICS_SWITCHING,
    OPENGL_PROFILE,
    CLIENT_API,
    CONTEXT_CREATION_API,
    CONTEXT_ROBUSTNESS,
    CONTEXT_RELEASE_BEHAVIOR,
    CONTEXT_VERSION_MAJOR,
    CONTEXT_VERSION_MINOR,
    RED_BITS,
    GREEN_BITS,
    BLUE_BITS,
    ALPHA_BITS,
    DEPTH_BITS,
    STENCIL_BITS,
    ACCUM_RED_BITS,
    ACCUM_GREEN_BITS,
    ACCUM_BLUE_BITS,
    ACCUM_ALPHA_BITS,
    AUX_BUFFERS,
    SAMPLES,
    REFRESH_RATE,
    COCOA_FRAME_NAME,
    X11_CLASS_NAME,
    X11_INSTANCE_NAME
};

enum class OpenGLProfile { ANY_PROFILE, CORE_PROFILE, COMPAT_PROFILE };

enum class ClientAPI { NO_API, OPENGL, OPENGL_ES };

enum class ContextCreationAPI { NATIVE, EGL, OSMESA };

enum class ContextRobustness { NO_ROBUSTNESS, NO_RESET_NOTIFICATION, LOSE_CONTEXT_ON_RESET };

enum class ContextReleaseBehavior { ANY_RELEASE_BEHAVIOR, RELEASE_BEHAVIOR_FLUSH, RELEASE_BEHAVIOR_NONE };

struct ContextVersion {
    int major;
    int minor;

    auto operator==(const ContextVersion& other) const -> bool { return other.major == major && other.minor == minor; }
    auto operator!=(const ContextVersion& other) const -> bool { return !(*this == other); }
};

struct WindowSize {
    int width;
    int height;
};

class WindowHints {
public:
    auto resizable(const bool value = true) -> WindowHints&;
    auto visible(const bool value = true) -> WindowHints&;
    auto decorated(const bool value = true) -> WindowHints&;
    auto focused(const bool value = true) -> WindowHints&;
    auto auto_iconify(const bool value = true) -> WindowHints&;
    auto floating(const bool value = false) -> WindowHints&;
    auto maximized(const bool value = false) -> WindowHints&;
    auto center_cursor(const bool value = true) -> WindowHints&;
    auto transparent_framebuffer(const bool value = false) -> WindowHints&;
    auto focus_on_show(const bool value = true) -> WindowHints&;
    auto scale_to_monitor(const bool value = false) -> WindowHints&;
    auto stereo(const bool value = false) -> WindowHints&;
    auto srgb_capable(const bool value = false) -> WindowHints&;
    auto doublebuffer(const bool value = true) -> WindowHints&;
    auto opengl_forward_compat(const bool value = false) -> WindowHints&;
    auto opengl_debug_context(const bool value = false) -> WindowHints&;
    auto cocoa_retina_framebuffer(const bool value = true) -> WindowHints&;
    auto cocoa_graphics_switching(const bool value = false) -> WindowHints&;
    auto opengl_profile(const OpenGLProfile& value = OpenGLProfile::ANY_PROFILE) -> WindowHints&;
    auto client_api(const ClientAPI& value = ClientAPI::OPENGL) -> WindowHints&;
    auto context_creation_api(const ContextCreationAPI& value = ContextCreationAPI::NATIVE) -> WindowHints&;
    auto context_robustness(const ContextRobustness& value = ContextRobustness::NO_ROBUSTNESS) -> WindowHints&;
    auto context_release_behavior(const ContextReleaseBehavior& value = ContextReleaseBehavior::ANY_RELEASE_BEHAVIOR) -> WindowHints&;
    auto context_version(const ContextVersion& value = {1, 0}) -> WindowHints&;
    auto red_bits(const int value = 8) -> WindowHints&;
    auto green_bits(const int value = 8) -> WindowHints&;
    auto blue_bits(const int value = 8) -> WindowHints&;
    auto alpha_bits(const int value = 8) -> WindowHints&;
    auto depth_bits(const int value = 24) -> WindowHints&;
    auto stencil_bits(const int value = 8) -> WindowHints&;
    auto accum_red_bits(const int value = 0) -> WindowHints&;
    auto accum_green_bits(const int value = 0) -> WindowHints&;
    auto accum_blue_bits(const int value = 0) -> WindowHints&;
    auto accum_alpha_bits(const int value = 0) -> WindowHints&;
    auto aux_buffers(const int value = 0) -> WindowHints&;
    auto samples(const int value = 0) -> WindowHints&;
    auto refresh_rate(const int value = DONT_CARE) -> WindowHints&;
    auto cocoa_frame_name(const std::string& value = {}) -> WindowHints&;
    auto x11_class_name(const std::string& value = {}) -> WindowHints&;
    auto x11_instance_name(const std::string& value = {}) -> WindowHints&;

private:
    bool resizable_{true};
    bool visible_{true};
    bool decorated_{true};
    bool focused_{true};
    bool auto_iconify_{true};
    bool floating_{false};
    bool maximized_{false};
    bool center_cursor_{true};
    bool transparent_framebuffer_{false};
    bool focus_on_show_{true};
    bool scale_to_monitor_{false};
    bool stereo_{false};
    bool srgb_capable_{false};
    bool doublebuffer_{true};
    bool opengl_forward_compat_{false};
    bool opengl_debug_context_{false};
    bool cocoa_retina_framebuffer_{true};
    bool cocoa_graphics_switching_{false};
    OpenGLProfile opengl_profile_{OpenGLProfile::ANY_PROFILE};
    ClientAPI client_api_{ClientAPI::OPENGL};
    ContextCreationAPI context_creation_api_{ContextCreationAPI::NATIVE};
    ContextRobustness context_robustness_{ContextRobustness::NO_ROBUSTNESS};
    ContextReleaseBehavior context_release_behavior_{ContextReleaseBehavior::ANY_RELEASE_BEHAVIOR};
    ContextVersion context_version_{1, 0};
    int red_bits_{8};
    int green_bits_{8};
    int blue_bits_{8};
    int alpha_bits_{8};
    int depth_bits_{24};
    int stencil_bits_{8};
    int accum_red_bits_{0};
    int accum_green_bits_{0};
    int accum_blue_bits_{0};
    int accum_alpha_bits_{0};
    int aux_buffers_{0};
    int samples_{0};
    int refresh_rate_{DONT_CARE};
    std::string cocoa_frame_name_{};
    std::string x11_class_name_{};
    std::string x11_instance_name_{};

    friend class Window;
};

auto glfw_hint_key(const WindowHintsKeys& key) -> int;
auto glfw_hint_value(const OpenGLProfile& value) -> int;
auto glfw_hint_value(const ClientAPI& value) -> int;
auto glfw_hint_value(const ContextCreationAPI& value) -> int;
auto glfw_hint_value(const ContextRobustness& value) -> int;
auto glfw_hint_value(const ContextReleaseBehavior& value) -> int;

}  // namespace glfwcxx
