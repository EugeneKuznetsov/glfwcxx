#include <gtest/gtest.h>

#include "glfwcxx/Core.hpp"
#include "glfwcxx/CoreInitHints.hpp"

TEST(glfwcxx_core, throws_runtime_error_when_glfw_cannot_be_initialized_after_call_to_init)
{
    glfwcxx::CoreStub::reset();
    glfwcxx::CoreStub::init_failure();
    ASSERT_THROW(glfwcxx::Core::init(), std::runtime_error);
}

TEST(glfwcxx_core, successfully_initialized_after_call_to_init)
{
    glfwcxx::CoreStub::reset();
    ASSERT_NO_THROW(glfwcxx::Core::init());
}

TEST(glfwcxx_core, successfully_initialized_with_empty_init_hints)
{
    glfwcxx::CoreStub::reset();
    ASSERT_NO_THROW(glfwcxx::Core::init({}));
    EXPECT_FALSE(glfwcxx::CoreStub::was_inited_with_joystick_hat_buttons());
    EXPECT_FALSE(glfwcxx::CoreStub::was_inited_with_cocoa_menubar());
    EXPECT_FALSE(glfwcxx::CoreStub::was_inited_with_cocoa_chdir_resources());
}

TEST(glfwcxx_core, successfully_initialized_with_joystick_and_cocoa_menubar_init_hints)
{
    glfwcxx::CoreStub::reset();
    ASSERT_NO_THROW(glfwcxx::Core::init(glfwcxx::CoreInitHints{}.with_joystick_hat_buttons().with_cocoa_menubar()));
    EXPECT_TRUE(glfwcxx::CoreStub::was_inited_with_joystick_hat_buttons());
    EXPECT_TRUE(glfwcxx::CoreStub::was_inited_with_cocoa_menubar());
    EXPECT_FALSE(glfwcxx::CoreStub::was_inited_with_cocoa_chdir_resources());
}

TEST(glfwcxx_core, successfully_initialized_with_cocoa_chdir_resources)
{
    glfwcxx::CoreStub::reset();
    ASSERT_NO_THROW(glfwcxx::Core::init(glfwcxx::CoreInitHints{}.with_cocoa_chdir_resources()));
    EXPECT_FALSE(glfwcxx::CoreStub::was_inited_with_joystick_hat_buttons());
    EXPECT_FALSE(glfwcxx::CoreStub::was_inited_with_cocoa_menubar());
    EXPECT_TRUE(glfwcxx::CoreStub::was_inited_with_cocoa_chdir_resources());
}

TEST(glfwcxx_core, successfully_initialized_with_all_init_hints)
{
    glfwcxx::CoreStub::reset();
    ASSERT_NO_THROW(glfwcxx::Core::init({true, true, true}));
    EXPECT_TRUE(glfwcxx::CoreStub::was_inited_with_joystick_hat_buttons());
    EXPECT_TRUE(glfwcxx::CoreStub::was_inited_with_cocoa_menubar());
    EXPECT_TRUE(glfwcxx::CoreStub::was_inited_with_cocoa_chdir_resources());
}

TEST(glfwcxx_core, successfully_deinitialized_when_out_of_scope)
{
    glfwcxx::CoreStub::reset();
    {
        ASSERT_NO_THROW(glfwcxx::Core::init({true, true, true}));
    }
    EXPECT_TRUE(glfwcxx::CoreStub::was_deinitialized());
}
