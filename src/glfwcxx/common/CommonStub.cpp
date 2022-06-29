#include "glfwcxx/CommonStub.hpp"

#include <GLFW/glfw3.h>

auto glfwGetError(const char** description) -> int
{
    *description = glfwcxx::CommonStub::last_error_message_.c_str();
    return glfwcxx::CommonStub::last_error_code_;
}

namespace glfwcxx {

int CommonStub::last_error_code_ = GLFW_NO_ERROR;
std::string CommonStub::last_error_message_ = "";

auto CommonStub::reset() -> void
{
    last_error_code_ = GLFW_NO_ERROR;
    last_error_message_ = "";
}

auto CommonStub::set_error(const int error_code, const std::string& error_message) -> void
{
    last_error_code_ = error_code;
    last_error_message_ = error_message;
}

}  // namespace glfwcxx
