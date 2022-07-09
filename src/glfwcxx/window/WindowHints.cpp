#include "glfwcxx/WindowHints.hpp"

#include <GLFW/glfw3.h>

#define HINT_CASE(glfwcxx_key, glfw_key) \
    case glfwcxx_key:                    \
        return glfw_key;

#define HINT_CASE_DEFAULT() \
    default:                \
        return -1;

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

auto WindowHints::cocoa_retina_framebuffer(const bool value /*= true*/) -> WindowHints&
{
    cocoa_retina_framebuffer_ = value;
    return *this;
}

auto WindowHints::cocoa_graphics_switching(const bool value /*= false*/) -> WindowHints&
{
    cocoa_graphics_switching_ = value;
    return *this;
}

auto WindowHints::opengl_profile(const OpenGLProfile& value /*= OpenGLProfile::ANY_PROFILE*/) -> WindowHints&
{
    opengl_profile_ = value;
    return *this;
}

auto WindowHints::client_api(const ClientAPI& value /*= ClientAPI::OPENGL*/) -> WindowHints&
{
    client_api_ = value;
    return *this;
}

auto WindowHints::context_creation_api(const ContextCreationAPI& value /*= ContextCreationAPI::NATIVE*/) -> WindowHints&
{
    context_creation_api_ = value;
    return *this;
}

auto WindowHints::context_robustness(const ContextRobustness& value /*= ContextRobustness::NO_ROBUSTNESS*/) -> WindowHints&
{
    context_robustness_ = value;
    return *this;
}

auto WindowHints::context_release_behavior(const ContextReleaseBehavior& value /*= ContextReleaseBehavior::ANY_RELEASE_BEHAVIOR*/)
    -> WindowHints&
{
    context_release_behavior_ = value;
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

auto WindowHints::cocoa_frame_name(const std::string& value /*= {}*/) -> WindowHints&
{
    cocoa_frame_name_ = value;
    return *this;
}

auto WindowHints::x11_class_name(const std::string& value /*= {}*/) -> WindowHints&
{
    x11_class_name_ = value;
    return *this;
}

auto WindowHints::x11_instance_name(const std::string& value /*= {}*/) -> WindowHints&
{
    x11_instance_name_ = value;
    return *this;
}

auto glfw_hint_key(const WindowHintsKeys& key) -> int
{
    switch (key) {
        HINT_CASE(WindowHintsKeys::RESIZABLE, GLFW_RESIZABLE)
        HINT_CASE(WindowHintsKeys::VISIBLE, GLFW_VISIBLE)
        HINT_CASE(WindowHintsKeys::DECORATED, GLFW_DECORATED)
        HINT_CASE(WindowHintsKeys::FOCUSED, GLFW_FOCUSED)
        HINT_CASE(WindowHintsKeys::AUTO_ICONIFY, GLFW_AUTO_ICONIFY)
        HINT_CASE(WindowHintsKeys::FLOATING, GLFW_FLOATING)
        HINT_CASE(WindowHintsKeys::MAXIMIZED, GLFW_MAXIMIZED)
        HINT_CASE(WindowHintsKeys::CENTER_CURSOR, GLFW_CENTER_CURSOR)
        HINT_CASE(WindowHintsKeys::TRANSPARENT_FRAMEBUFFER, GLFW_TRANSPARENT_FRAMEBUFFER)
        HINT_CASE(WindowHintsKeys::FOCUS_ON_SHOW, GLFW_FOCUS_ON_SHOW)
        HINT_CASE(WindowHintsKeys::SCALE_TO_MONITOR, GLFW_SCALE_TO_MONITOR)
        HINT_CASE(WindowHintsKeys::STEREO, GLFW_STEREO)
        HINT_CASE(WindowHintsKeys::SRGB_CAPABLE, GLFW_SRGB_CAPABLE)
        HINT_CASE(WindowHintsKeys::DOUBLEBUFFER, GLFW_DOUBLEBUFFER)
        HINT_CASE(WindowHintsKeys::OPENGL_FORWARD_COMPAT, GLFW_OPENGL_FORWARD_COMPAT)
        HINT_CASE(WindowHintsKeys::OPENGL_DEBUG_CONTEXT, GLFW_OPENGL_DEBUG_CONTEXT)
        HINT_CASE(WindowHintsKeys::COCOA_RETINA_FRAMEBUFFER, GLFW_COCOA_RETINA_FRAMEBUFFER)
        HINT_CASE(WindowHintsKeys::COCOA_GRAPHICS_SWITCHING, GLFW_COCOA_GRAPHICS_SWITCHING)
        HINT_CASE(WindowHintsKeys::OPENGL_PROFILE, GLFW_OPENGL_PROFILE)
        HINT_CASE(WindowHintsKeys::CLIENT_API, GLFW_CLIENT_API)
        HINT_CASE(WindowHintsKeys::CONTEXT_CREATION_API, GLFW_CONTEXT_CREATION_API)
        HINT_CASE(WindowHintsKeys::CONTEXT_ROBUSTNESS, GLFW_CONTEXT_ROBUSTNESS)
        HINT_CASE(WindowHintsKeys::CONTEXT_RELEASE_BEHAVIOR, GLFW_CONTEXT_RELEASE_BEHAVIOR)
        HINT_CASE(WindowHintsKeys::CONTEXT_VERSION_MAJOR, GLFW_CONTEXT_VERSION_MAJOR)
        HINT_CASE(WindowHintsKeys::CONTEXT_VERSION_MINOR, GLFW_CONTEXT_VERSION_MINOR)
        HINT_CASE(WindowHintsKeys::RED_BITS, GLFW_RED_BITS)
        HINT_CASE(WindowHintsKeys::GREEN_BITS, GLFW_GREEN_BITS)
        HINT_CASE(WindowHintsKeys::BLUE_BITS, GLFW_BLUE_BITS)
        HINT_CASE(WindowHintsKeys::ALPHA_BITS, GLFW_ALPHA_BITS)
        HINT_CASE(WindowHintsKeys::DEPTH_BITS, GLFW_DEPTH_BITS)
        HINT_CASE(WindowHintsKeys::STENCIL_BITS, GLFW_STENCIL_BITS)
        HINT_CASE(WindowHintsKeys::ACCUM_RED_BITS, GLFW_ACCUM_RED_BITS)
        HINT_CASE(WindowHintsKeys::ACCUM_GREEN_BITS, GLFW_ACCUM_GREEN_BITS)
        HINT_CASE(WindowHintsKeys::ACCUM_BLUE_BITS, GLFW_ACCUM_BLUE_BITS)
        HINT_CASE(WindowHintsKeys::ACCUM_ALPHA_BITS, GLFW_ACCUM_ALPHA_BITS)
        HINT_CASE(WindowHintsKeys::AUX_BUFFERS, GLFW_AUX_BUFFERS)
        HINT_CASE(WindowHintsKeys::SAMPLES, GLFW_SAMPLES)
        HINT_CASE(WindowHintsKeys::REFRESH_RATE, GLFW_REFRESH_RATE)
        HINT_CASE(WindowHintsKeys::COCOA_FRAME_NAME, GLFW_COCOA_FRAME_NAME)
        HINT_CASE(WindowHintsKeys::X11_CLASS_NAME, GLFW_X11_CLASS_NAME)
        HINT_CASE(WindowHintsKeys::X11_INSTANCE_NAME, GLFW_X11_INSTANCE_NAME)
        HINT_CASE_DEFAULT()
    }
}

auto glfw_hint_value(const OpenGLProfile& value) -> int
{
    switch (value) {
        HINT_CASE(OpenGLProfile::ANY_PROFILE, GLFW_OPENGL_ANY_PROFILE);
        HINT_CASE(OpenGLProfile::CORE_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        HINT_CASE(OpenGLProfile::COMPAT_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
        HINT_CASE_DEFAULT()
    }
}

auto glfw_hint_value(const ClientAPI& value) -> int
{
    switch (value) {
        HINT_CASE(ClientAPI::NO_API, GLFW_NO_API);
        HINT_CASE(ClientAPI::OPENGL, GLFW_OPENGL_API);
        HINT_CASE(ClientAPI::OPENGL_ES, GLFW_OPENGL_ES_API);
        HINT_CASE_DEFAULT()
    }
}

auto glfw_hint_value(const ContextCreationAPI& value) -> int
{
    switch (value) {
        HINT_CASE(ContextCreationAPI::NATIVE, GLFW_NATIVE_CONTEXT_API);
        HINT_CASE(ContextCreationAPI::EGL, GLFW_EGL_CONTEXT_API);
        HINT_CASE(ContextCreationAPI::OSMESA, GLFW_OSMESA_CONTEXT_API);
        HINT_CASE_DEFAULT()
    }
}

auto glfw_hint_value(const ContextRobustness& value) -> int
{
    switch (value) {
        HINT_CASE(ContextRobustness::NO_ROBUSTNESS, GLFW_NO_ROBUSTNESS);
        HINT_CASE(ContextRobustness::NO_RESET_NOTIFICATION, GLFW_NO_RESET_NOTIFICATION);
        HINT_CASE(ContextRobustness::LOSE_CONTEXT_ON_RESET, GLFW_LOSE_CONTEXT_ON_RESET);
        HINT_CASE_DEFAULT()
    }
}

auto glfw_hint_value(const ContextReleaseBehavior& value) -> int
{
    switch (value) {
        HINT_CASE(ContextReleaseBehavior::ANY_RELEASE_BEHAVIOR, GLFW_ANY_RELEASE_BEHAVIOR);
        HINT_CASE(ContextReleaseBehavior::RELEASE_BEHAVIOR_FLUSH, GLFW_RELEASE_BEHAVIOR_FLUSH);
        HINT_CASE(ContextReleaseBehavior::RELEASE_BEHAVIOR_NONE, GLFW_RELEASE_BEHAVIOR_NONE);
        HINT_CASE_DEFAULT()
    }
}

}  // namespace glfwcxx
