#pragma once

static constexpr int GLFW_FALSE = 0;
static constexpr int GLFW_TRUE = 1;

static constexpr int GLFW_JOYSTICK_HAT_BUTTONS = 0x00050001;
static constexpr int GLFW_COCOA_CHDIR_RESOURCES = 0x00051001;
static constexpr int GLFW_COCOA_MENUBAR = 0x00051002;

static constexpr int GLFW_NO_ERROR = 0;
static constexpr int GLFW_NOT_INITIALIZED = 0x00010001;

static constexpr int GLFW_CONTEXT_VERSION_MAJOR = 0x00022002;
static constexpr int GLFW_CONTEXT_VERSION_MINOR = 0x00022003;
static constexpr int GLFW_OPENGL_PROFILE = 0x00022008;

struct GLFWmonitor;
struct GLFWwindow;

extern auto glfwGetError(const char** description) -> int;

extern auto glfwInit() -> int;
extern auto glfwTerminate() -> void;
extern auto glfwInitHint(int hint, int value) -> void;

extern auto glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) -> GLFWwindow*;
extern auto glfwDestroyWindow(GLFWwindow* window) -> void;
extern auto glfwMakeContextCurrent(GLFWwindow* window) -> void;
extern auto glfwWindowHint(int hint, int value) -> void;
extern auto glfwPollEvents() -> void;
extern auto glfwSwapBuffers(GLFWwindow* window) -> void;
