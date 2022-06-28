#include <gtest/gtest.h>

#include "glfwcxx/Core.hpp"

TEST(glfwcxx_core, throws_runtime_error_when_glfw_cannot_be_initialized_after_call_to_init)
{
    glfwcxx::CoreStub::init_failure();
    ASSERT_THROW(glfwcxx::Core::init(), std::runtime_error);
}

TEST(glfwcxx_core, successfully_initialized_after_call_to_init)
{
    glfwcxx::CoreStub::init_success();
    ASSERT_NO_THROW(glfwcxx::Core::init());
}
