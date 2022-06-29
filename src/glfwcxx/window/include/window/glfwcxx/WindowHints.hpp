#pragma once

namespace glfwcxx {

enum class OpenGLProfile : int { ANY_PROFILE = 0, CORE_PROFILE = 0x00032001, COMPAT_PROFILE = 0x00032002 };

struct ContextVersion {
    int major;
    int minor;

    auto operator==(const ContextVersion& other) const -> bool { return other.major == major && other.minor == minor; }
    auto operator!=(const ContextVersion& other) const -> bool { return !(*this == other); }
};

struct WindowHints {
    OpenGLProfile profile{OpenGLProfile::ANY_PROFILE};
    ContextVersion version{1, 0};

    auto opengl_profile(const OpenGLProfile& value) -> WindowHints&;
    auto context_version(const ContextVersion& value) -> WindowHints&;
};

}  // namespace glfwcxx
