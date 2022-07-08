#include "glfwcxx/WindowHints.hpp"

namespace glfwcxx {

auto WindowHints::resizable(const bool value /*= true*/) -> WindowHints&
{
    resizable_ = value;
    return *this;
}

auto WindowHints::opengl_profile(const OpenGLProfile& value) -> WindowHints&
{
    opengl_profile_ = value;
    return *this;
}

auto WindowHints::context_version(const ContextVersion& value) -> WindowHints&
{
    context_version_ = value;
    return *this;
}

}  // namespace glfwcxx
