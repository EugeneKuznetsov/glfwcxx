#pragma once

static constexpr int GLFW_FALSE = 0;
static constexpr int GLFW_TRUE = 1;

static constexpr int GLFW_JOYSTICK_HAT_BUTTONS = 0x00050001;
static constexpr int GLFW_COCOA_CHDIR_RESOURCES = 0x00051001;
static constexpr int GLFW_COCOA_MENUBAR = 0x00051002;

static constexpr int GLFW_DONT_CARE = -1;

static constexpr int GLFW_NO_ERROR = 0;
static constexpr int GLFW_NOT_INITIALIZED = 0x00010001;

static constexpr int GLFW_FOCUSED = 0x00020001;
static constexpr int GLFW_RESIZABLE = 0x00020003;
static constexpr int GLFW_VISIBLE = 0x00020004;
static constexpr int GLFW_DECORATED = 0x00020005;
static constexpr int GLFW_AUTO_ICONIFY = 0x00020006;
static constexpr int GLFW_FLOATING = 0x00020007;
static constexpr int GLFW_MAXIMIZED = 0x00020008;
static constexpr int GLFW_CENTER_CURSOR = 0x00020009;
static constexpr int GLFW_TRANSPARENT_FRAMEBUFFER = 0x0002000A;
static constexpr int GLFW_FOCUS_ON_SHOW = 0x0002000C;
static constexpr int GLFW_RED_BITS = 0x00021001;
static constexpr int GLFW_GREEN_BITS = 0x00021002;
static constexpr int GLFW_BLUE_BITS = 0x00021003;
static constexpr int GLFW_ALPHA_BITS = 0x00021004;
static constexpr int GLFW_DEPTH_BITS = 0x00021005;
static constexpr int GLFW_STENCIL_BITS = 0x00021006;
static constexpr int GLFW_ACCUM_RED_BITS = 0x00021007;
static constexpr int GLFW_ACCUM_GREEN_BITS = 0x00021008;
static constexpr int GLFW_ACCUM_BLUE_BITS = 0x00021009;
static constexpr int GLFW_ACCUM_ALPHA_BITS = 0x0002100A;
static constexpr int GLFW_AUX_BUFFERS = 0x0002100B;
static constexpr int GLFW_STEREO = 0x0002100C;
static constexpr int GLFW_SAMPLES = 0x0002100D;
static constexpr int GLFW_SRGB_CAPABLE = 0x0002100D;
static constexpr int GLFW_REFRESH_RATE = 0x0002100F;
static constexpr int GLFW_DOUBLEBUFFER = 0x00021010;
static constexpr int GLFW_CONTEXT_VERSION_MAJOR = 0x00022002;
static constexpr int GLFW_CONTEXT_VERSION_MINOR = 0x00022003;
static constexpr int GLFW_OPENGL_PROFILE = 0x00022008;
static constexpr int GLFW_SCALE_TO_MONITOR = 0x0002200C;

static constexpr int GLFW_OPENGL_ANY_PROFILE = 0;
static constexpr int GLFW_OPENGL_CORE_PROFILE = 0x00032001;
static constexpr int GLFW_OPENGL_COMPAT_PROFILE = 0x00032002;

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
extern auto glfwWindowShouldClose(GLFWwindow* window) -> int;
