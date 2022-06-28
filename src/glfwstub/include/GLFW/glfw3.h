#pragma once

static constexpr int GLFW_FALSE = 0;
static constexpr int GLFW_TRUE = 1;

extern auto glfwInit() -> int;
extern auto glfwTerminate() -> void;
