#pragma once

namespace glfwcxx {

class CoreStub {
public:
    static auto init_failure() -> void;
    static auto init_success() -> void;

    static auto init_return_value() -> int { return init_return_value_; }

private:
    static int init_return_value_;
};

}  // namespace glfwcxx
