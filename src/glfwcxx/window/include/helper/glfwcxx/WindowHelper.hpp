#pragma once

namespace glfwcxx {

enum class OpenGLProfile;
enum class ClientAPI;
enum class ContextCreationAPI;
enum class ContextRobustness;
enum class ContextReleaseBehavior;

namespace helpers {

enum class WindowHintsKeys {
    resizable,
    visible,
    decorated,
    focused,
    auto_iconify,
    floating,
    maximized,
    center_cursor,
    transparent_framebuffer,
    focus_on_show,
    scale_to_monitor,
    stereo,
    srgb_capable,
    doublebuffer,
    opengl_forward_compat,
    opengl_debug_context,
    cocoa_retina_framebuffer,
    cocoa_graphics_switching,
    opengl_profile,
    client_api,
    context_creation_api,
    context_robustness,
    context_release_behavior,
    context_version_major,
    context_version_minor,
    red_bits,
    green_bits,
    blue_bits,
    alpha_bits,
    depth_bits,
    stencil_bits,
    accum_red_bits,
    accum_green_bits,
    accum_blue_bits,
    accum_alpha_bits,
    aux_buffers,
    samples,
    refresh_rate,
    cocoa_frame_name,
    x11_class_name,
    x11_instance_name
};

auto glfw_hint_key(const WindowHintsKeys& key) -> int;
auto glfw_hint_value(const OpenGLProfile& value) -> int;
auto glfw_hint_value(const ClientAPI& value) -> int;
auto glfw_hint_value(const ContextCreationAPI& value) -> int;
auto glfw_hint_value(const ContextRobustness& value) -> int;
auto glfw_hint_value(const ContextReleaseBehavior& value) -> int;

}  // namespace helpers

}  // namespace glfwcxx
