#include "glfwcxx/WindowHints.hpp"

namespace glfwcxx {

auto WindowHints::opengl_profile(const OpenGLProfile& /*profile*/) -> WindowHints&
{
    return *this;
}

auto WindowHints::context_version(const int /*major*/, const int /*minor*/) -> WindowHints&
{
    return *this;
}

}  // namespace glfwcxx
