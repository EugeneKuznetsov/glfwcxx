#pragma once

#include <functional>
#include <set>
#include <string>
#include <map>

struct GLFWmonitor;
struct GLFWwindow;

using GLFWkeyfun = void (*)(GLFWwindow* window, int key, int scancode, int action, int mods);
using GLFWwindowsizefun = void (*)(GLFWwindow* window, int width, int height);
using GLFWframebuffersizefun = void (*)(GLFWwindow* window, int width, int height);
using GLFWwindowcontentscalefun = void (*)(GLFWwindow* window, float xscale, float yscale);

extern auto glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> GLFWwindow*;
extern auto glfwDestroyWindow(GLFWwindow* window) -> void;
extern auto glfwMakeContextCurrent(GLFWwindow* window) -> void;
extern auto glfwWindowHint(int hint, int value) -> void;
extern auto glfwWindowHintString(int hint, const char* value) -> void;
extern auto glfwPollEvents() -> void;
extern auto glfwSwapBuffers(GLFWwindow* window) -> void;
extern auto glfwWindowShouldClose(GLFWwindow* window) -> int;
extern auto glfwSetWindowShouldClose(GLFWwindow* window, int value) -> void;
extern auto glfwSetKeyCallback(GLFWwindow* window, GLFWkeyfun callback) -> GLFWkeyfun;
extern auto glfwSetWindowUserPointer(GLFWwindow* window, void* pointer) -> void;
extern auto glfwGetWindowUserPointer(GLFWwindow* window) -> void*;
extern auto glfwGetWindowSize(GLFWwindow* window, int* width, int* height) -> void;
extern auto glfwGetFramebufferSize(GLFWwindow* window, int* width, int* height) -> void;
extern auto glfwGetWindowContentScale(GLFWwindow* window, float* xscale, float* yscale) -> void;
extern auto glfwSetWindowSizeCallback(GLFWwindow* window, GLFWwindowsizefun callback) -> GLFWwindowsizefun;
extern auto glfwSetFramebufferSizeCallback(GLFWwindow* window, GLFWframebuffersizefun callback) -> GLFWframebuffersizefun;
extern auto glfwSetWindowContentScaleCallback(GLFWwindow* window, GLFWwindowcontentscalefun callback) -> GLFWwindowcontentscalefun;

namespace glfwcxx {

using callback_function_t = std::function<void()>;
using window_hints_int_map_t = std::map<int, int>;
using window_hints_str_map_t = std::map<int, std::string>;

class WindowStub {
public:
    static auto reset() -> void;

    static auto create_window_failure() -> void;
    static auto make_context_current_failure() -> void;
    static auto close_window() -> void;
    static auto keyboard_input(int key, int action, std::set<int> modifiers) -> void;

    static auto created_window_with_arguments(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> bool;
    static auto window_int_hint_applied_count() -> std::size_t;
    static auto window_str_hint_applied_count() -> std::size_t;
    static auto window_int_hint_applied(int hint, int value) -> bool;
    static auto window_str_hint_applied(int hint, const char* value) -> bool;
    static auto was_destroyed() -> bool;
    static auto poll_events_call_count() -> std::size_t;
    static auto swap_buffers_call_count() -> std::size_t;

    static auto poll_events_call_callback(callback_function_t callback) -> void;

private:
    static GLFWwindow* last_created_window_;
    static GLFWwindow* last_destroyed_window_;
    static bool was_destroyed_;
    static int last_passed_width_;
    static int last_passed_height_;
    static std::string last_passed_title_;
    static GLFWmonitor* last_passed_monitor_;
    static GLFWwindow* last_passed_share_;
    static window_hints_int_map_t window_int_hints_;
    static window_hints_str_map_t window_str_hints_;
    static std::size_t poll_events_call_count_;
    static std::size_t swap_buffers_call_count_;
    static bool close_window_;
    static callback_function_t poll_events_callback_;
    static GLFWkeyfun keyboard_callback_;
    static void* window_user_pointer_;

    friend auto ::glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> GLFWwindow*;
    friend auto ::glfwDestroyWindow(GLFWwindow* window) -> void;
    friend auto ::glfwMakeContextCurrent(GLFWwindow* window) -> void;
    friend auto ::glfwWindowHint(int hint, int value) -> void;
    friend auto ::glfwWindowHintString(int hint, const char* value) -> void;
    friend auto ::glfwPollEvents() -> void;
    friend auto ::glfwSwapBuffers(GLFWwindow* window) -> void;
    friend auto ::glfwWindowShouldClose(GLFWwindow* window) -> int;
    friend auto ::glfwSetWindowShouldClose(GLFWwindow* window, int value) -> void;
    friend auto ::glfwSetKeyCallback(GLFWwindow* window, GLFWkeyfun callback) -> GLFWkeyfun;
    friend auto ::glfwSetWindowUserPointer(GLFWwindow* window, void* pointer) -> void;
    friend auto ::glfwGetWindowUserPointer(GLFWwindow* window) -> void*;
    friend auto ::glfwGetWindowSize(GLFWwindow* window, int* width, int* height) -> void;
    friend auto ::glfwGetFramebufferSize(GLFWwindow* window, int* width, int* height) -> void;
    friend auto ::glfwGetWindowContentScale(GLFWwindow* window, float* xscale, float* yscale) -> void;
    friend auto ::glfwSetWindowSizeCallback(GLFWwindow* window, GLFWwindowsizefun callback) -> GLFWwindowsizefun;
    friend auto ::glfwSetFramebufferSizeCallback(GLFWwindow* window, GLFWframebuffersizefun callback) -> GLFWframebuffersizefun;
    friend auto ::glfwSetWindowContentScaleCallback(GLFWwindow* window, GLFWwindowcontentscalefun callback) -> GLFWwindowcontentscalefun;
};

}  // namespace glfwcxx
