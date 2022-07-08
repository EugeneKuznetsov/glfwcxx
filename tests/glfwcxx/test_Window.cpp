#include <list>
#include <utility>

#include <GLFW/glfw3.h>

#include <gtest/gtest.h>

#include <glfwcxx/Window.hpp>
#include <glfwcxx/WindowStub.hpp>

class glfwcxx_window : public testing::Test {
public:
    auto SetUp() -> void { glfwcxx::WindowStub::reset(); }

    auto CREATE_AND_EXPECT(const glfwcxx::WindowHints& actual_hints, const std::list<std::pair<int, int>>& expected_hints) -> void
    {
        EXPECT_NO_THROW(static_cast<void>(glfwcxx::Window::create_window({800, 600}, "", actual_hints)));
        EXPECT_EQ(glfwcxx::WindowStub::window_hint_applied_count(), expected_hints.size());
        for (const auto& expected_hint : expected_hints)
            EXPECT_TRUE(glfwcxx::WindowStub::window_hint_applied(expected_hint.first, expected_hint.second));
    }
};

TEST_F(glfwcxx_window, throws_runtime_error_when_cannot_be_created_due_to_error)
{
    glfwcxx::WindowStub::create_window_failure();
    ASSERT_THROW(static_cast<void>(glfwcxx::Window::create_window({800, 600}, "")), std::runtime_error);
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

TEST_F(glfwcxx_window, successfully_created_with_predefined_default_window_hints_without_underlying_call)
{
    ASSERT_NO_THROW(static_cast<void>(glfwcxx::Window::create_window({123, 456}, "abc")));
    EXPECT_TRUE(glfwcxx::WindowStub::created_window_with_arguments(123, 456, "abc", nullptr, nullptr));
    ASSERT_EQ(glfwcxx::WindowStub::window_hint_applied_count(), 0);
}

TEST_F(glfwcxx_window, successfully_created_with_resizable_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.resizable(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_resizable_window_hint_set_to_false)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.resizable(false), {{GLFW_RESIZABLE, GLFW_FALSE}});
}

TEST_F(glfwcxx_window, successfully_created_with_visible_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.visible(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_visible_window_hint_set_to_false)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.visible(false), {{GLFW_VISIBLE, GLFW_FALSE}});
}

TEST_F(glfwcxx_window, successfully_created_with_decorated_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.decorated(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_decorated_window_hint_set_to_false)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.decorated(false), {{GLFW_DECORATED, GLFW_FALSE}});
}

TEST_F(glfwcxx_window, successfully_created_with_focused_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.focused(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_focused_window_hint_set_to_false)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.focused(false), {{GLFW_FOCUSED, GLFW_FALSE}});
}

TEST_F(glfwcxx_window, successfully_created_with_auto_iconify_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.auto_iconify(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_auto_iconify_window_hint_set_to_false)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.auto_iconify(false), {{GLFW_AUTO_ICONIFY, GLFW_FALSE}});
}

TEST_F(glfwcxx_window, successfully_created_with_floating_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.floating(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_floating_window_hint_set_to_true)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.floating(true), {{GLFW_FLOATING, GLFW_TRUE}});
}

TEST_F(glfwcxx_window, successfully_created_with_maximized_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.maximized(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_maximized_window_hint_set_to_true)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.maximized(true), {{GLFW_MAXIMIZED, GLFW_TRUE}});
}

TEST_F(glfwcxx_window, successfully_created_with_center_cursor_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.center_cursor(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_center_cursor_window_hint_set_to_false)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.center_cursor(false), {{GLFW_CENTER_CURSOR, GLFW_FALSE}});
}

TEST_F(glfwcxx_window, successfully_created_with_transparent_framebuffer_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.transparent_framebuffer(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_transparent_framebuffer_window_hint_set_to_true)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.transparent_framebuffer(true), {{GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE}});
}

TEST_F(glfwcxx_window, successfully_created_with_focus_on_show_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.focus_on_show(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_focus_on_show_window_hint_set_to_false)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.focus_on_show(false), {{GLFW_FOCUS_ON_SHOW, GLFW_FALSE}});
}

TEST_F(glfwcxx_window, successfully_created_with_scale_to_monitor_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.scale_to_monitor(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_scale_to_monitor_window_hint_set_to_true)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.scale_to_monitor(true), {{GLFW_SCALE_TO_MONITOR, GLFW_TRUE}});
}

TEST_F(glfwcxx_window, successfully_created_with_opengl_any_profile_window_hint_without_underlying_call)
{
    const auto& profile = glfwcxx::OpenGLProfile::ANY_PROFILE;
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.opengl_profile(profile), {});
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

TEST_F(glfwcxx_window, successfully_created_with_context_version_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.context_version(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_context_version_3_2_window_hint)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.context_version({3, 2}), {{GLFW_CONTEXT_VERSION_MAJOR, 3}, {GLFW_CONTEXT_VERSION_MINOR, 2}});
}

TEST_F(glfwcxx_window, successfully_created_with_red_bits_window_hint_without_underlying_call)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.red_bits(), {});
}

TEST_F(glfwcxx_window, successfully_created_with_red_bits_dont_care_window_hint)
{
    CREATE_AND_EXPECT(glfwcxx::WindowHints{}.red_bits(glfwcxx::DONT_CARE), {{GLFW_RED_BITS, GLFW_DONT_CARE}});
}

TEST_F(glfwcxx_window, should_poll_events_successfully)
{
    auto callback_works = false;
    glfwcxx::WindowStub::poll_events_call_callback([&callback_works]() -> void { callback_works = true; });
    ASSERT_EQ(glfwcxx::WindowStub::poll_events_call_count(), 0);
    auto window = glfwcxx::Window::create_window({800, 600}, "");
    window->poll_events();
    EXPECT_EQ(glfwcxx::WindowStub::poll_events_call_count(), 1);
    EXPECT_EQ(callback_works, true);
}

TEST_F(glfwcxx_window, should_swap_buffers_successfully)
{
    ASSERT_EQ(glfwcxx::WindowStub::swap_buffers_call_count(), 0);
    auto window = glfwcxx::Window::create_window({800, 600}, "");
    window->swap_buffers();
    EXPECT_EQ(glfwcxx::WindowStub::swap_buffers_call_count(), 1);
}

TEST_F(glfwcxx_window, should_close_returns_true_when_requested_to_close_window)
{
    auto window = glfwcxx::Window::create_window({800, 600}, "");
    EXPECT_FALSE(window->should_close());
    glfwcxx::WindowStub::close_window();
    EXPECT_TRUE(window->should_close());
}
