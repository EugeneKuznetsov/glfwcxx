#include "glfwcxx/Common.hpp"

#include <GLFW/glfw3.h>

namespace glfwcxx {

auto get_last_error() -> std::pair<Error, std::string>
{
    const char* description{nullptr};
    if (const auto error_code = glfwGetError(&description); GLFW_NO_ERROR != error_code)
        return {static_cast<Error>(error_code), std::string{description}};
    return {Error::NO_ERROR, ""};
}

}  // namespace glfwcxx
