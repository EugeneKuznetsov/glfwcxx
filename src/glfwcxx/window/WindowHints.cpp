#include "glfwcxx/WindowHints.hpp"

namespace glfwcxx {

auto WindowHints::opengl_profile(const OpenGLProfile& value) -> WindowHints&
{
    profile = value;
    return *this;
}

auto WindowHints::context_version(const ContextVersion& value) -> WindowHints&
{
    version = value;
    return *this;
}

}  // namespace glfwcxx
