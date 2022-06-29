#pragma once

namespace glfwcxx {

class WindowStub {
public:
    static auto reset() -> void;

    static auto create_window_failure() -> void;
    static auto make_context_current_failure() -> void;

    static auto created_window_with_arguments(int width, int height, const char* title, void* monitor, void* shared) -> bool;
    static auto window_hint_applied_count() -> int;
    static auto window_hint_applied(int hint, int value) -> bool;
    static auto was_destroyed() -> bool;
};

}  // namespace glfwcxx
