#pragma once

#include <string>

namespace glfwcxx {

static constexpr int dont_care = -1;

enum class OpenGLProfile { any_profile, core, compat };

enum class ClientAPI { no_api, opengl, opengl_es };

enum class ContextCreationAPI { native, egl, osmesa };

enum class ContextRobustness { no_robustness, no_reset_notification, lose_context_on_reset };

enum class ContextReleaseBehavior { any_release_behavior, release_behavior_flush, release_behavior_none };

struct ContextVersion {
    int major;
    int minor;

    auto operator==(const ContextVersion& other) const -> bool { return other.major == major && other.minor == minor; }
    auto operator!=(const ContextVersion& other) const -> bool { return !(*this == other); }
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
    auto opengl_profile(const OpenGLProfile& value = OpenGLProfile::any_profile) -> WindowHints&;
    auto client_api(const ClientAPI& value = ClientAPI::opengl) -> WindowHints&;
    auto context_creation_api(const ContextCreationAPI& value = ContextCreationAPI::native) -> WindowHints&;
    auto context_robustness(const ContextRobustness& value = ContextRobustness::no_robustness) -> WindowHints&;
    auto context_release_behavior(const ContextReleaseBehavior& value = ContextReleaseBehavior::any_release_behavior) -> WindowHints&;
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
    auto refresh_rate(const int value = dont_care) -> WindowHints&;
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
    OpenGLProfile opengl_profile_{OpenGLProfile::any_profile};
    ClientAPI client_api_{ClientAPI::opengl};
    ContextCreationAPI context_creation_api_{ContextCreationAPI::native};
    ContextRobustness context_robustness_{ContextRobustness::no_robustness};
    ContextReleaseBehavior context_release_behavior_{ContextReleaseBehavior::any_release_behavior};
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
    int refresh_rate_{dont_care};
    std::string cocoa_frame_name_{};
    std::string x11_class_name_{};
    std::string x11_instance_name_{};

    friend class Window;
};

}  // namespace glfwcxx
