#pragma once

#include <GLFW/export.hpp>

static constexpr int GLFW_FALSE = 0;
static constexpr int GLFW_TRUE = 1;

auto glfwInit() -> int;
auto glfwTerminate() -> void;

namespace glfwcxx {

struct GLFW_API_GLFWSTUB_EXPORT Stub {
    static bool glfwInit;
};

}  // namespace glfwcxx
