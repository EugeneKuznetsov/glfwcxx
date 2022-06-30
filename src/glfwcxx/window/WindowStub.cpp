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

auto WindowStub::created_window_with_arguments(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> bool
{
    return last_passed_width_ == width && last_passed_height_ == height && last_passed_title_ == title && last_passed_monitor_ == monitor &&
           last_passed_share_ == share;
}

auto WindowStub::window_hint_applied_count() -> std::size_t
{
    return window_int_hints_.size();
}

auto WindowStub::window_hint_applied(int hint, int value) -> bool
{
    if (window_int_hints_.cend() == window_int_hints_.find(hint))
        return false;
    return window_int_hints_[hint] == value;
}

auto WindowStub::was_destroyed() -> bool
{
    return was_destroyed_;
}

}  // namespace glfwcxx