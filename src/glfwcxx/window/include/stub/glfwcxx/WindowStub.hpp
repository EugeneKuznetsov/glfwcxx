#pragma once

#include <string>
#include <unordered_map>

struct GLFWmonitor;
struct GLFWwindow;

extern auto glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> GLFWwindow*;
extern auto glfwDestroyWindow(GLFWwindow* window) -> void;
extern auto glfwMakeContextCurrent(GLFWwindow* window) -> void;
extern auto glfwWindowHint(int hint, int value) -> void;

namespace glfwcxx {

using window_hints_int_map = std::unordered_map<int, int>;

class WindowStub {
public:
    static auto reset() -> void;

    static auto create_window_failure() -> void;
    static auto make_context_current_failure() -> void;

    static auto created_window_with_arguments(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> bool;
    static auto window_hint_applied_count() -> std::size_t;
    static auto window_hint_applied(int hint, int value) -> bool;
    static auto was_destroyed() -> bool;

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

    friend auto ::glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> GLFWwindow*;
    friend auto ::glfwDestroyWindow(GLFWwindow* window) -> void;
    friend auto ::glfwMakeContextCurrent(GLFWwindow* window) -> void;
    friend auto ::glfwWindowHint(int hint, int value) -> void;
};

}  // namespace glfwcxx