#include "glfwcxx/WindowStub.hpp"

namespace glfwcxx {

auto WindowStub::reset() -> void {}

auto WindowStub::create_window_failure() -> void {}

auto WindowStub::make_context_current_failure() -> void {}

auto WindowStub::created_window_with_arguments(int /*width*/, int /*height*/, const char* /*title*/, void* /*monitor*/, void* /*shared*/)
    -> bool
{
    return false;
}

auto WindowStub::window_hint_applied_count() -> int
{
    return 0;
}

auto WindowStub::window_hint_applied(int /*hint*/, int /*value*/) -> bool
{
    return false;
}

auto WindowStub::was_destroyed() -> bool
{
    return false;
}

}  // namespace glfwcxx
