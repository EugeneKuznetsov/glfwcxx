#include "glfwcxx/WindowHints.hpp"

namespace glfwcxx {

auto WindowHints::resizable(const bool value /*= true*/) -> WindowHints&
{
    resizable_ = value;
    return *this;
}

auto WindowHints::visible(const bool value /*= true*/) -> WindowHints&
{
    visible_ = value;
    return *this;
}

auto WindowHints::decorated(const bool value /*= true*/) -> WindowHints&
{
    decorated_ = value;
    return *this;
}

auto WindowHints::focused(const bool value /*= true*/) -> WindowHints&
{
    focused_ = value;
    return *this;
}

auto WindowHints::auto_iconify(const bool value /*= true*/) -> WindowHints&
{
    auto_iconify_ = value;
    return *this;
}

auto WindowHints::floating(const bool value /*= false*/) -> WindowHints&
{
    floating_ = value;
    return *this;
}

auto WindowHints::maximized(const bool value /*= false*/) -> WindowHints&
{
    maximized_ = value;
    return *this;
}

auto WindowHints::center_cursor(const bool value /*= true*/) -> WindowHints&
{
    center_cursor_ = value;
    return *this;
}

auto WindowHints::transparent_framebuffer(const bool value /*= false*/) -> WindowHints&
{
    transparent_framebuffer_ = value;
    return *this;
}

auto WindowHints::focus_on_show(const bool value /*= true*/) -> WindowHints&
{
    focus_on_show_ = value;
    return *this;
}

auto WindowHints::scale_to_monitor(const bool value /*= false*/) -> WindowHints&
{
    scale_to_monitor_ = value;
    return *this;
}

auto WindowHints::stereo(const bool value /*= false*/) -> WindowHints&
{
    stereo_ = value;
    return *this;
}

auto WindowHints::srgb_capable(const bool value /*= false*/) -> WindowHints&
{
    srgb_capable_ = value;
    return *this;
}

auto WindowHints::doublebuffer(const bool value /*= true*/) -> WindowHints&
{
    doublebuffer_ = value;
    return *this;
}

auto WindowHints::opengl_forward_compat(const bool value /*= false*/) -> WindowHints&
{
    opengl_forward_compat_ = value;
    return *this;
}

auto WindowHints::opengl_debug_context(const bool value /*= false*/) -> WindowHints&
{
    opengl_debug_context_ = value;
    return *this;
}

auto WindowHints::opengl_profile(const OpenGLProfile& value) -> WindowHints&
{
    opengl_profile_ = value;
    return *this;
}

auto WindowHints::context_version(const ContextVersion& value /*= {1, 0}*/) -> WindowHints&
{
    context_version_ = value;
    return *this;
}

auto WindowHints::red_bits(const int value /*= 8*/) -> WindowHints&
{
    red_bits_ = value;
    return *this;
}

auto WindowHints::green_bits(const int value /*= 8*/) -> WindowHints&
{
    green_bits_ = value;
    return *this;
}

auto WindowHints::blue_bits(const int value /*= 8*/) -> WindowHints&
{
    blue_bits_ = value;
    return *this;
}

auto WindowHints::alpha_bits(const int value /*= 8*/) -> WindowHints&
{
    alpha_bits_ = value;
    return *this;
}

auto WindowHints::depth_bits(const int value /*= 24*/) -> WindowHints&
{
    depth_bits_ = value;
    return *this;
}

auto WindowHints::stencil_bits(const int value /*= 8*/) -> WindowHints&
{
    stencil_bits_ = value;
    return *this;
}

auto WindowHints::accum_red_bits(const int value /*= 0*/) -> WindowHints&
{
    accum_red_bits_ = value;
    return *this;
}

auto WindowHints::accum_green_bits(const int value /*= 0*/) -> WindowHints&
{
    accum_green_bits_ = value;
    return *this;
}

auto WindowHints::accum_blue_bits(const int value /*= 0*/) -> WindowHints&
{
    accum_blue_bits_ = value;
    return *this;
}

auto WindowHints::accum_alpha_bits(const int value /*= 0*/) -> WindowHints&
{
    accum_alpha_bits_ = value;
    return *this;
}

auto WindowHints::aux_buffers(const int value /*= 0*/) -> WindowHints&
{
    aux_buffers_ = value;
    return *this;
}

auto WindowHints::samples(const int value /*= 0*/) -> WindowHints&
{
    samples_ = value;
    return *this;
}

auto WindowHints::refresh_rate(const int value /*= DONT_CARE*/) -> WindowHints&
{
    refresh_rate_ = value;
    return *this;
}

}  // namespace glfwcxx
