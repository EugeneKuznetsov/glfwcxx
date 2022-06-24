#pragma once

namespace glfwcxx {

class GlfwCore final {
    GlfwCore(const GlfwCore&) = delete;
    GlfwCore& operator=(const GlfwCore&) = delete;

    GlfwCore(GlfwCore&&) = delete;
    GlfwCore& operator=(GlfwCore&&) = delete;

public:
    explicit GlfwCore() = default;
    ~GlfwCore() = default;
};

}  // namespace glfwcxx
