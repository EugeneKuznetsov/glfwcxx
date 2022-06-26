#pragma once

static constexpr int GLFW_FALSE = 0;
static constexpr int GLFW_TRUE = 1;

auto glfwInit() -> int;
auto glfwTerminate() -> void;

namespace glfwcxx {

struct Stub {
    static bool glfwInit;
};

}  // namespace glfwcxx
