#pragma once

#include <utility>
#include <string>

#ifdef GLFWCXX_STUB
#include <glfwcxx/CommonStub.hpp>
#endif

namespace glfwcxx {

enum class Error : int { NO_ERROR = 0, NOT_INITIALIZED = 0x00010001 };

auto get_last_error() -> std::pair<Error, std::string>;

}  // namespace glfwcxx
