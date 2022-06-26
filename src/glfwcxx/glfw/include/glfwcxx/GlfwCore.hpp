#pragma once

namespace glfwcxx {

class GlfwCore final {
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
