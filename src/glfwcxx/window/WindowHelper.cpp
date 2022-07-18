#include "glfwcxx/WindowHelper.hpp"

#include <GLFW/glfw3.h>

#include "glfwcxx/WindowHints.hpp"

#define GLFWCXX_TO_GLFW_CASE(glfwcxx_value, glfw_value) \
    case glfwcxx_value:                                 \
        return glfw_value;

#define GLFW_TO_GLFWCXX_CASE(glfwcxx_value, glfw_value) \
    case glfw_value:                                    \
        return glfwcxx_value;

#define GLFWCXX_ENUM_DEFAULT(glfwcxx_value) \
    default:                                \
        return glfwcxx_value;

#define GLFWCXX_DEFAULT() \
    default:              \
        return -1;

namespace glfwcxx::helpers {

auto glfw_hint_key(const WindowHintsKeys& key) -> int
{
    switch (key) {
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::resizable, GLFW_RESIZABLE)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::visible, GLFW_VISIBLE)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::decorated, GLFW_DECORATED)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::focused, GLFW_FOCUSED)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::auto_iconify, GLFW_AUTO_ICONIFY)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::floating, GLFW_FLOATING)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::maximized, GLFW_MAXIMIZED)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::center_cursor, GLFW_CENTER_CURSOR)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::transparent_framebuffer, GLFW_TRANSPARENT_FRAMEBUFFER)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::focus_on_show, GLFW_FOCUS_ON_SHOW)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::scale_to_monitor, GLFW_SCALE_TO_MONITOR)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::stereo, GLFW_STEREO)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::srgb_capable, GLFW_SRGB_CAPABLE)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::doublebuffer, GLFW_DOUBLEBUFFER)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::opengl_forward_compat, GLFW_OPENGL_FORWARD_COMPAT)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::opengl_debug_context, GLFW_OPENGL_DEBUG_CONTEXT)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::cocoa_retina_framebuffer, GLFW_COCOA_RETINA_FRAMEBUFFER)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::cocoa_graphics_switching, GLFW_COCOA_GRAPHICS_SWITCHING)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::opengl_profile, GLFW_OPENGL_PROFILE)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::client_api, GLFW_CLIENT_API)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::context_creation_api, GLFW_CONTEXT_CREATION_API)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::context_robustness, GLFW_CONTEXT_ROBUSTNESS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::context_release_behavior, GLFW_CONTEXT_RELEASE_BEHAVIOR)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::context_version_major, GLFW_CONTEXT_VERSION_MAJOR)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::context_version_minor, GLFW_CONTEXT_VERSION_MINOR)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::red_bits, GLFW_RED_BITS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::green_bits, GLFW_GREEN_BITS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::blue_bits, GLFW_BLUE_BITS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::alpha_bits, GLFW_ALPHA_BITS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::depth_bits, GLFW_DEPTH_BITS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::stencil_bits, GLFW_STENCIL_BITS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::accum_red_bits, GLFW_ACCUM_RED_BITS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::accum_green_bits, GLFW_ACCUM_GREEN_BITS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::accum_blue_bits, GLFW_ACCUM_BLUE_BITS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::accum_alpha_bits, GLFW_ACCUM_ALPHA_BITS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::aux_buffers, GLFW_AUX_BUFFERS)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::samples, GLFW_SAMPLES)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::refresh_rate, GLFW_REFRESH_RATE)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::cocoa_frame_name, GLFW_COCOA_FRAME_NAME)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::x11_class_name, GLFW_X11_CLASS_NAME)
        GLFWCXX_TO_GLFW_CASE(WindowHintsKeys::x11_instance_name, GLFW_X11_INSTANCE_NAME)
        GLFWCXX_DEFAULT()
    }
}

auto glfw_hint_value(const OpenGLProfile& value) -> int
{
    switch (value) {
        GLFWCXX_TO_GLFW_CASE(OpenGLProfile::any_profile, GLFW_OPENGL_ANY_PROFILE);
        GLFWCXX_TO_GLFW_CASE(OpenGLProfile::core, GLFW_OPENGL_CORE_PROFILE);
        GLFWCXX_TO_GLFW_CASE(OpenGLProfile::compat, GLFW_OPENGL_COMPAT_PROFILE);
        GLFWCXX_DEFAULT()
    }
}

auto glfw_hint_value(const ClientAPI& value) -> int
{
    switch (value) {
        GLFWCXX_TO_GLFW_CASE(ClientAPI::no_api, GLFW_NO_API);
        GLFWCXX_TO_GLFW_CASE(ClientAPI::opengl, GLFW_OPENGL_API);
        GLFWCXX_TO_GLFW_CASE(ClientAPI::opengl_es, GLFW_OPENGL_ES_API);
        GLFWCXX_DEFAULT()
    }
}

auto glfw_hint_value(const ContextCreationAPI& value) -> int
{
    switch (value) {
        GLFWCXX_TO_GLFW_CASE(ContextCreationAPI::native, GLFW_NATIVE_CONTEXT_API);
        GLFWCXX_TO_GLFW_CASE(ContextCreationAPI::egl, GLFW_EGL_CONTEXT_API);
        GLFWCXX_TO_GLFW_CASE(ContextCreationAPI::osmesa, GLFW_OSMESA_CONTEXT_API);
        GLFWCXX_DEFAULT()
    }
}

auto glfw_hint_value(const ContextRobustness& value) -> int
{
    switch (value) {
        GLFWCXX_TO_GLFW_CASE(ContextRobustness::no_robustness, GLFW_NO_ROBUSTNESS);
        GLFWCXX_TO_GLFW_CASE(ContextRobustness::no_reset_notification, GLFW_NO_RESET_NOTIFICATION);
        GLFWCXX_TO_GLFW_CASE(ContextRobustness::lose_context_on_reset, GLFW_LOSE_CONTEXT_ON_RESET);
        GLFWCXX_DEFAULT()
    }
}

auto glfw_hint_value(const ContextReleaseBehavior& value) -> int
{
    switch (value) {
        GLFWCXX_TO_GLFW_CASE(ContextReleaseBehavior::any_release_behavior, GLFW_ANY_RELEASE_BEHAVIOR);
        GLFWCXX_TO_GLFW_CASE(ContextReleaseBehavior::release_behavior_flush, GLFW_RELEASE_BEHAVIOR_FLUSH);
        GLFWCXX_TO_GLFW_CASE(ContextReleaseBehavior::release_behavior_none, GLFW_RELEASE_BEHAVIOR_NONE);
        GLFWCXX_DEFAULT()
    }
}

}  // namespace glfwcxx::helpers
