#pragma once

#include <string>

namespace glfwcxx {

static constexpr int DONT_CARE = -1;

enum class OpenGLProfile : int { ANY_PROFILE = 0, CORE_PROFILE = 0x00032001, COMPAT_PROFILE = 0x00032002 };

enum class ClientAPI : int { NO_API = 0, OPENGL = 0x00030001, OPENGL_ES = 0x00030002 };

enum class ContextCreationAPI : int { NATIVE = 0x00036001, EGL = 0x00036002, OSMESA = 0x00036003 };

enum class ContextRobustness : int { NO_ROBUSTNESS = 0, NO_RESET_NOTIFICATION = 0x00031001, LOSE_CONTEXT_ON_RESET = 0x00031002 };

enum class ContextReleaseBehavior : int {
    ANY_RELEASE_BEHAVIOR = 0,
    RELEASE_BEHAVIOR_FLUSH = 0x00035001,
    RELEASE_BEHAVIOR_NONE = 0x00035002
};

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

    friend class Window;
};

}  // namespace glfwcxx
