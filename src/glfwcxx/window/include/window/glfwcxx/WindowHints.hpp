#pragma once

namespace glfwcxx {

enum class OpenGLProfile : int { ANY_PROFILE = 0, CORE_PROFILE = 0x00032001, COMPAT_PROFILE = 0x00032002 };

struct WindowHints {
    auto opengl_profile(const OpenGLProfile& profile) -> WindowHints&;
    auto context_version(const int major, const int minor) -> WindowHints&;
};

}  // namespace glfwcxx
