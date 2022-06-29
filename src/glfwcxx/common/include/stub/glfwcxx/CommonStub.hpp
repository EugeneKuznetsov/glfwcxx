#pragma once

#include <string>

extern auto glfwGetError(const char** description) -> int;

namespace glfwcxx {

class CommonStub {
public:
    static auto reset() -> void;

    static auto set_error(const int error_code, const std::string& error_message) -> void;

private:
    static int last_error_code_;
    static std::string last_error_message_;

    friend auto ::glfwGetError(const char** description) -> int;
};

}  // namespace glfwcxx
