#pragma once

#include <functional>
#include <string>
#include <unordered_map>

struct GLFWmonitor;
struct GLFWwindow;

extern auto glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> GLFWwindow*;
extern auto glfwDestroyWindow(GLFWwindow* window) -> void;
extern auto glfwMakeContextCurrent(GLFWwindow* window) -> void;
extern auto glfwWindowHint(int hint, int value) -> void;
extern auto glfwPollEvents() -> void;
extern auto glfwSwapBuffers(GLFWwindow* window) -> void;
extern auto glfwWindowShouldClose(GLFWwindow* window) -> int;

namespace glfwcxx {

using callback_function = std::function<void()>;
using window_hints_int_map = std::unordered_map<int, int>;

class WindowStub {
public:
    static auto reset() -> void;

    static auto create_window_failure() -> void;
    static auto make_context_current_failure() -> void;
    static auto close_window() -> void;

    static auto created_window_with_arguments(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> bool;
    static auto window_hint_applied_count() -> std::size_t;
    static auto window_hint_applied(int hint, int value) -> bool;
    static auto was_destroyed() -> bool;
    static auto poll_events_call_count() -> std::size_t;
    static auto swap_buffers_call_count() -> std::size_t;

    static auto poll_events_call_callback(callback_function callback) -> void;

private:
    static GLFWwindow* last_created_window_;
    static GLFWwindow* last_destroyed_window_;
    static bool was_destroyed_;
    static int last_passed_width_;
    static int last_passed_height_;
    static std::string last_passed_title_;
    static GLFWmonitor* last_passed_monitor_;
    static GLFWwindow* last_passed_share_;
    static window_hints_int_map window_int_hints_;
    static std::size_t poll_events_call_count_;
    static std::size_t swap_buffers_call_count_;
    static bool close_window_;
    static callback_function poll_events_callback_;

    friend auto ::glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> GLFWwindow*;
    friend auto ::glfwDestroyWindow(GLFWwindow* window) -> void;
    friend auto ::glfwMakeContextCurrent(GLFWwindow* window) -> void;
    friend auto ::glfwWindowHint(int hint, int value) -> void;
    friend auto ::glfwPollEvents() -> void;
    friend auto ::glfwSwapBuffers(GLFWwindow* window) -> void;
    friend auto ::glfwWindowShouldClose(GLFWwindow* window) -> int;
};

}  // namespace glfwcxx
