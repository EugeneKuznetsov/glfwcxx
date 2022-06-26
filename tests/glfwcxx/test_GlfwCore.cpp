#include <gtest/gtest.h>

#include "glfwcxx/GlfwCore.hpp"
#include "GLFW/glfw3.h"

TEST(glfw_core, throws_runtime_error_when_glfw_cannot_be_initialized_after_call_to_init)
{
    glfwcxx::Stub::glfwInit = GLFW_FALSE;
    ASSERT_THROW(glfwcxx::GlfwCore::init(), std::runtime_error);
}

TEST(glfw_core, successfully_initialized_after_call_to_init)
{
    glfwcxx::Stub::glfwInit = GLFW_TRUE;
    ASSERT_NO_THROW(glfwcxx::GlfwCore::init());
}
