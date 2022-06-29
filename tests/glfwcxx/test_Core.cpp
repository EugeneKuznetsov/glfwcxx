#include <gtest/gtest.h>

#include "glfwcxx/Core.hpp"
#include "glfwcxx/CoreInitHints.hpp"

class glfwcxx_core : public testing::Test {
public:
    auto SetUp() -> void { glfwcxx::CoreStub::reset(); }

    auto EXPECT_HINTS(bool joystick_hat_buttons, bool cocoa_chdir_resources, bool cocoa_menubar)
    {
        EXPECT_EQ(glfwcxx::CoreStub::was_inited_with_joystick_hat_buttons(), joystick_hat_buttons);
        EXPECT_EQ(glfwcxx::CoreStub::was_inited_with_cocoa_chdir_resources(), cocoa_chdir_resources);
        EXPECT_EQ(glfwcxx::CoreStub::was_inited_with_cocoa_menubar(), cocoa_menubar);
    }
};

TEST_F(glfwcxx_core, throws_runtime_error_when_glfw_cannot_be_initialized_after_call_to_init)
{
    glfwcxx::CoreStub::init_failure();
    ASSERT_THROW(static_cast<void>(glfwcxx::Core::init()), std::runtime_error);
    EXPECT_FALSE(glfwcxx::CoreStub::was_deinitialized());
}

TEST_F(glfwcxx_core, successfully_initialized_after_call_to_init)
{
    ASSERT_NO_THROW(static_cast<void>(glfwcxx::Core::init()));
}

TEST_F(glfwcxx_core, successfully_initialized_with_empty_init_hints)
{
    static_cast<void>(glfwcxx::Core::init({}));
    EXPECT_HINTS(false, false, false);
}

TEST_F(glfwcxx_core, successfully_initialized_with_joystick_and_cocoa_menubar_init_hints)
{
    static_cast<void>(glfwcxx::Core::init(glfwcxx::CoreInitHints{}.with_joystick_hat_buttons().with_cocoa_menubar()));
    EXPECT_HINTS(true, false, true);
}

TEST_F(glfwcxx_core, successfully_initialized_with_cocoa_chdir_resources)
{
    static_cast<void>(glfwcxx::Core::init(glfwcxx::CoreInitHints{}.with_cocoa_chdir_resources()));
    EXPECT_HINTS(false, true, false);
}

TEST_F(glfwcxx_core, successfully_initialized_with_all_init_hints)
{
    static_cast<void>(glfwcxx::Core::init({true, true, true}));
    EXPECT_HINTS(true, true, true);
}

TEST_F(glfwcxx_core, successfully_deinitialized_when_out_of_scope)
{
    EXPECT_FALSE(glfwcxx::CoreStub::was_deinitialized());
    {
        auto glfw = glfwcxx::Core::init({true, true, true});
        EXPECT_FALSE(glfwcxx::CoreStub::was_deinitialized());
    }
    EXPECT_TRUE(glfwcxx::CoreStub::was_deinitialized());
}
