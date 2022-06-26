#pragma once

#include <glfwcxx/export_core.hpp>

namespace glfwcxx {

class GLFWCXX_API_CORE_EXPORT GlfwCore final {
    GlfwCore(const GlfwCore&) = delete;
    GlfwCore& operator=(const GlfwCore&) = delete;

    GlfwCore(GlfwCore&&) = delete;
    GlfwCore& operator=(GlfwCore&&) = delete;

    explicit GlfwCore();
    ~GlfwCore();

public:
    static auto init() -> GlfwCore&;
};

}  // namespace glfwcxx
