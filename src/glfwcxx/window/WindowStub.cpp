#include "glfwcxx/WindowStub.hpp"

#include "glfwcxx/CommonStub.hpp"

static constexpr int GLFW_FALSE = 0;

struct GLFWmonitor {};

struct GLFWwindow {};

auto glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> GLFWwindow*
{
    glfwcxx::WindowStub::last_passed_width_ = width;
    glfwcxx::WindowStub::last_passed_height_ = height;
    glfwcxx::WindowStub::last_passed_title_ = title;
    glfwcxx::WindowStub::last_passed_monitor_ = monitor;
    glfwcxx::WindowStub::last_passed_share_ = share;
    return glfwcxx::WindowStub::last_created_window_;
}

auto glfwDestroyWindow(GLFWwindow* window) -> void
{
    glfwcxx::WindowStub::last_destroyed_window_ = window;
    glfwcxx::WindowStub::was_destroyed_ = (glfwcxx::WindowStub::last_created_window_ == window);
}

auto glfwMakeContextCurrent(GLFWwindow* /*window*/) -> void {}

auto glfwWindowHint(int hint, int value) -> void
{
    glfwcxx::WindowStub::window_int_hints_[hint] = value;
}

auto glfwWindowHintString(int hint, const char* value) -> void
{
    glfwcxx::WindowStub::window_str_hints_[hint] = value;
}

auto glfwPollEvents() -> void
{
    glfwcxx::WindowStub::poll_events_call_count_++;
    if (nullptr != glfwcxx::WindowStub::poll_events_callback_)
        glfwcxx::WindowStub::poll_events_callback_();
}

auto glfwSwapBuffers(GLFWwindow* /*window*/) -> void
{
    glfwcxx::WindowStub::swap_buffers_call_count_++;
}

auto glfwWindowShouldClose(GLFWwindow* /*window*/) -> int
{
    return glfwcxx::WindowStub::close_window_ ? 1 : 0;
}

auto glfwSetWindowShouldClose(GLFWwindow* /*window*/, int value) -> void
{
    glfwcxx::WindowStub::close_window_ = GLFW_FALSE != value;
}

auto glfwSetKeyCallback(GLFWwindow* /*window*/, GLFWkeyfun callback) -> GLFWkeyfun
{
    glfwcxx::WindowStub::keyboard_callback_ = callback;
    return callback;
}

auto glfwSetWindowUserPointer(GLFWwindow* /*window*/, void* pointer) -> void
{
    glfwcxx::WindowStub::window_user_pointer_ = pointer;
}

auto glfwGetWindowUserPointer(GLFWwindow* /*window*/) -> void*
{
    return glfwcxx::WindowStub::window_user_pointer_;
}

auto glfwGetWindowSize(GLFWwindow* /*window*/, int* width, int* height) -> void
{
    const auto& size = glfwcxx::WindowStub::window_size_;
    *width = size.width;
    *height = size.height;
}

auto glfwGetFramebufferSize(GLFWwindow* /*window*/, int* width, int* height) -> void
{
    const auto& size = glfwcxx::WindowStub::frame_buffer_size_;
    *width = size.width;
    *height = size.height;
}

auto glfwGetWindowContentScale(GLFWwindow* /*window*/, float* xscale, float* yscale) -> void
{
    const auto& scale = glfwcxx::WindowStub::window_content_scale_;
    *xscale = scale.xscale;
    *yscale = scale.yscale;
}

auto glfwSetWindowSizeCallback(GLFWwindow* /*window*/, GLFWwindowsizefun callback) -> GLFWwindowsizefun
{
    glfwcxx::WindowStub::window_size_callback_ = callback;
    return callback;
}

auto glfwSetFramebufferSizeCallback(GLFWwindow* /*window*/, GLFWframebuffersizefun callback) -> GLFWframebuffersizefun
{
    glfwcxx::WindowStub::frame_buffer_size_callback_ = callback;
    return callback;
}

auto glfwSetWindowContentScaleCallback(GLFWwindow* /*window*/, GLFWwindowcontentscalefun callback) -> GLFWwindowcontentscalefun
{
    glfwcxx::WindowStub::window_content_scale_callback_ = callback;
    return callback;
}

namespace glfwcxx {

GLFWwindow* WindowStub::last_created_window_ = (GLFWwindow*)1234;
GLFWwindow* WindowStub::last_destroyed_window_ = nullptr;
bool WindowStub::was_destroyed_ = false;
int WindowStub::last_passed_width_ = -1;
int WindowStub::last_passed_height_ = -1;
std::string WindowStub::last_passed_title_ = "";
GLFWmonitor* WindowStub::last_passed_monitor_ = nullptr;
GLFWwindow* WindowStub::last_passed_share_ = nullptr;
window_hints_int_map_t WindowStub::window_int_hints_ = {};
window_hints_str_map_t WindowStub::window_str_hints_ = {};
std::size_t WindowStub::poll_events_call_count_ = 0;
std::size_t WindowStub::swap_buffers_call_count_ = 0;
bool WindowStub::close_window_ = false;
callback_function_t WindowStub::poll_events_callback_ = nullptr;
GLFWkeyfun WindowStub::keyboard_callback_ = nullptr;
GLFWwindowsizefun WindowStub::window_size_callback_ = nullptr;
GLFWframebuffersizefun WindowStub::frame_buffer_size_callback_ = nullptr;
GLFWwindowcontentscalefun WindowStub::window_content_scale_callback_ = nullptr;
void* WindowStub::window_user_pointer_ = nullptr;
WindowStub::WindowSize WindowStub::window_size_ = {0, 0};
WindowStub::FrameBufferSize WindowStub::frame_buffer_size_ = {0, 0};
WindowStub::WindowContentScale WindowStub::window_content_scale_ = {0.0f, 0.0f};

auto WindowStub::reset() -> void
{
    last_created_window_ = (GLFWwindow*)1234;
    last_destroyed_window_ = nullptr;
    was_destroyed_ = false;
    last_passed_width_ = -1;
    last_passed_height_ = -1;
    last_passed_title_ = "";
    last_passed_monitor_ = nullptr;
    last_passed_share_ = nullptr;
    window_int_hints_.clear();
    window_str_hints_.clear();
    poll_events_call_count_ = 0;
    swap_buffers_call_count_ = 0;
    close_window_ = false;
    poll_events_callback_ = nullptr;
    keyboard_callback_ = nullptr;
    window_size_callback_ = nullptr;
    frame_buffer_size_callback_ = nullptr;
    window_content_scale_callback_ = nullptr;
    window_user_pointer_ = nullptr;
    window_size_ = {0, 0};
    frame_buffer_size_ = {0, 0};
    window_content_scale_ = {0.0f, 0.0f};
    CommonStub::reset();
}

auto WindowStub::create_window_failure() -> void
{
    last_created_window_ = nullptr;
}

auto WindowStub::make_context_current_failure() -> void
{
    CommonStub::set_error(1, "error message");
}

auto WindowStub::close_window() -> void
{
    close_window_ = true;
}

auto WindowStub::keyboard_input(int key, int action, std::set<int> modifiers) -> void
{
    if (nullptr == keyboard_callback_)
        return;

    const int scancode = 0;
    int mods = 0;
    for (const auto& modifier : modifiers)
        mods |= modifier;
    keyboard_callback_(last_created_window_, key, scancode, action, mods);
}

auto WindowStub::set_window_size(int width, int height) -> void
{
    window_size_ = {width, height};
}

auto WindowStub::set_frame_buffer_size(int width, int height) -> void
{
    frame_buffer_size_ = {width, height};
}

auto WindowStub::set_window_content_scale(float xscale, float yscale) -> void
{
    window_content_scale_ = {xscale, yscale};
}

auto WindowStub::notify_window_size() -> void
{
    window_size_callback_(last_created_window_, window_size_.width, window_size_.height);
}

auto WindowStub::notify_frame_buffer_size() -> void
{
    frame_buffer_size_callback_(last_created_window_, frame_buffer_size_.width, frame_buffer_size_.height);
}

auto WindowStub::notify_window_content_scale() -> void
{
    window_content_scale_callback_(last_created_window_, window_content_scale_.xscale, window_content_scale_.yscale);
}

auto WindowStub::created_window_with_arguments(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> bool
{
    return last_passed_width_ == width && last_passed_height_ == height && last_passed_title_ == title && last_passed_monitor_ == monitor &&
           last_passed_share_ == share;
}

auto WindowStub::window_int_hint_applied_count() -> std::size_t
{
    return window_int_hints_.size();
}

auto WindowStub::window_str_hint_applied_count() -> std::size_t
{
    return window_str_hints_.size();
}

auto WindowStub::window_int_hint_applied(int hint, int value) -> bool
{
    if (window_int_hints_.cend() == window_int_hints_.find(hint))
        return false;
    return window_int_hints_[hint] == value;
}

auto WindowStub::window_str_hint_applied(int hint, const char* value) -> bool
{
    if (window_str_hints_.cend() == window_str_hints_.find(hint))
        return false;
    return window_str_hints_[hint] == std::string{value};
}

auto WindowStub::was_destroyed() -> bool
{
    return was_destroyed_;
}

auto WindowStub::poll_events_call_count() -> std::size_t
{
    return poll_events_call_count_;
}

auto WindowStub::swap_buffers_call_count() -> std::size_t
{
    return swap_buffers_call_count_;
}

auto WindowStub::poll_events_call_callback(callback_function_t callback) -> void
{
    poll_events_callback_ = callback;
}

}  // namespace glfwcxx
