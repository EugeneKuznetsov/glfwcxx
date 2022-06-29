#include <list>
#include <utility>

#include <gtest/gtest.h>

#include "glfwcxx/Window.hpp"

class glfwcxx_window : public testing::Test {
public:
    auto SetUp() -> void { glfwcxx::WindowStub::reset(); }

    auto CREATE_AND_EXPECT(const glfwcxx::WindowHints& actual_hints, const std::list<std::pair<int, int>>& expected_hints) -> void
    {
        EXPECT_NO_THROW(glfwcxx::Window::create_window({800, 600}, "", actual_hints));
        EXPECT_EQ(glfwcxx::WindowStub::window_hint_applied_count(), expected_hints.size());
        for (const auto& expected_hint : expected_hints)
            EXPECT_TRUE(glfwcxx::WindowStub::window_hint_applied(expected_hint.first, expected_hint.second));
    }
};

static constexpr int GLFW_CONTEXT_VERSION_MAJOR = 0x00022002;
static constexpr int GLFW_CONTEXT_VERSION_MINOR = 0x00022003;
static constexpr int GLFW_OPENGL_PROFILE = 0x00022008;

static constexpr int GLFW_OPENGL_ANY_PROFILE = 0;
static constexpr int GLFW_OPENGL_CORE_PROFILE = 0x00032001;
static constexpr int GLFW_OPENGL_COMPAT_PROFILE = 0x00032002;

TEST_F(glfwcxx_window, throws_runtime_error_when_cannot_be_created_due_to_error)
{
    glfwcxx::WindowStub::create_window_failure();
    ASSERT_THROW(glfwcxx::Window::create_window({800, 600}, ""), std::runtime_error);
}

TEST_F(glfwcxx_window, throws_runtime_error_when_context_cannot_be_made_current_due_to_error)
{
    glfwcxx::WindowStub::make_context_current_failure();
    auto window = glfwcxx::Window::create_window({800, 600}, "");
    ASSERT_THROW(window->make_context_current(), std::runtime_error);
}

TEST_F(glfwcxx_window, successfully_destroyed_when_out_of_scope)
{
    EXPECT_FALSE(glfwcxx::WindowStub::was_destroyed());
    {
        auto window = glfwcxx::Window::create_window({800, 600}, "");
        EXPECT_FALSE(glfwcxx::WindowStub::was_destroyed());
    }
    EXPECT_TRUE(glfwcxx::WindowStub::was_destroyed());
}

TEST_F(glfwcxx_window, successfully_makes_context_current_after_window_creation)
{
    auto window = glfwcxx::Window::create_window({800, 600}, "");
    ASSERT_NO_THROW(window->make_context_current());
}

TEST_F(glfwcxx_window, successfully_created_with_predefined_default_window_hints)
{
    ASSERT_NO_THROW(glfwcxx::Window::create_window({123, 456}, "abc"));
    EXPECT_TRUE(glfwcxx::WindowStub::created_window_with_arguments(123, 456, "abc", nullptr, nullptr));
    ASSERT_EQ(glfwcxx::WindowStub::window_hint_applied_count(), 3);
    EXPECT_TRUE(glfwcxx::WindowStub::window_hint_applied(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE));
    EXPECT_TRUE(glfwcxx::WindowStub::window_hint_applied(GLFW_CONTEXT_VERSION_MAJOR, 4));
    EXPECT_TRUE(glfwcxx::WindowStub::window_hint_applied(GLFW_CONTEXT_VERSION_MINOR, 0));
}

TEST_F(glfwcxx_window, successfully_created_with_opengl_any_profile_window_hint)
{
    const auto& profile = glfwcxx::OpenGLProfile::ANY_PROFILE;
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.opengl_profile(profile), {{GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE}});
}

TEST_F(glfwcxx_window, successfully_created_with_opengl_core_profile_window_hint)
{
    const auto& profile = glfwcxx::OpenGLProfile::CORE_PROFILE;
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.opengl_profile(profile), {{GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE}});
}

TEST_F(glfwcxx_window, successfully_created_with_opengl_compat_profile_window_hint)
{
    const auto& profile = glfwcxx::OpenGLProfile::COMPAT_PROFILE;
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.opengl_profile(profile), {{GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE}});
}

TEST_F(glfwcxx_window, successfully_created_with_context_version_window_hint)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.context_version(3, 2), {{GLFW_CONTEXT_VERSION_MAJOR, 3}, {GLFW_CONTEXT_VERSION_MINOR, 2}});
}
