#pragma once

#include <unordered_map>

extern auto glfwInit() -> int;
extern auto glfwInitHint(int hint, int value) -> void;

namespace glfwcxx {

using init_hints_map = std::unordered_map<int, int>;

class CoreStub {
public:
    static auto reset() -> void;

    static auto init_failure() -> void;
    static auto init_success() -> void;

    static auto was_inited_with_joystick_hat_buttons(const int and_the_value_was = 1) -> bool;
    static auto was_inited_with_cocoa_chdir_resources(const int and_the_value_was = 1) -> bool;
    static auto was_inited_with_cocoa_menubar(const int and_the_value_was = 1) -> bool;

private:
    static int init_return_value_;
    static init_hints_map init_hints_;

    friend auto ::glfwInit() -> int;
    friend auto ::glfwInitHint(int hint, int value) -> void;
};

}  // namespace glfwcxx
