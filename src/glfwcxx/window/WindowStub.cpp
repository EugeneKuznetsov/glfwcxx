#include "glfwcxx/WindowStub.hpp"

#include "glfwcxx/CommonStub.hpp"

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

namespace glfwcxx {

GLFWwindow* WindowStub::last_created_window_ = (GLFWwindow*)1234;
GLFWwindow* WindowStub::last_destroyed_window_ = nullptr;
bool WindowStub::was_destroyed_ = false;
int WindowStub::last_passed_width_ = -1;
int WindowStub::last_passed_height_ = -1;
std::string WindowStub::last_passed_title_ = "";
GLFWmonitor* WindowStub::last_passed_monitor_ = nullptr;
GLFWwindow* WindowStub::last_passed_share_ = nullptr;
window_hints_int_map WindowStub::window_int_hints_ = {};
window_hints_str_map WindowStub::window_str_hints_ = {};
std::size_t WindowStub::poll_events_call_count_ = 0;
std::size_t WindowStub::swap_buffers_call_count_ = 0;
bool WindowStub::close_window_ = false;
callback_function WindowStub::poll_events_callback_ = nullptr;

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

auto WindowStub::keyboard_input(int /*key*/, int /*action*/) -> void {}

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

auto WindowStub::poll_events_call_callback(callback_function callback) -> void
{
    poll_events_callback_ = callback;
}

}  // namespace glfwcxx
