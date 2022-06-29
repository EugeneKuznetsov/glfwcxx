#pragma once

static constexpr int GLFW_FALSE = 0;
static constexpr int GLFW_TRUE = 1;

static constexpr int GLFW_JOYSTICK_HAT_BUTTONS = 0x00050001;
static constexpr int GLFW_COCOA_CHDIR_RESOURCES = 0x00051001;
static constexpr int GLFW_COCOA_MENUBAR = 0x00051002;

static constexpr int GLFW_NO_ERROR = 0;
static constexpr int GLFW_NOT_INITIALIZED = 0x00010001;

extern auto glfwInit() -> int;
extern auto glfwTerminate() -> void;
extern auto glfwInitHint(int hint, int value) -> void;
extern auto glfwGetError(const char** description) -> int;
