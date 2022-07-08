#pragma once

namespace glfwcxx {

enum class OpenGLProfile : int { ANY_PROFILE = 0, CORE_PROFILE = 0x00032001, COMPAT_PROFILE = 0x00032002 };

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
    auto opengl_profile(const OpenGLProfile& value) -> WindowHints&;
    auto context_version(const ContextVersion& value = {1, 0}) -> WindowHints&;

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
    OpenGLProfile opengl_profile_{OpenGLProfile::ANY_PROFILE};
    ContextVersion context_version_{1, 0};

    friend class Window;
};

}  // namespace glfwcxx
