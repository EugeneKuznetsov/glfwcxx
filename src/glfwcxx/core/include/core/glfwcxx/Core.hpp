#pragma once

#include <memory>

#ifdef GLFWCXX_STUB
#include <glfwcxx/CoreStub.hpp>
#endif

namespace glfwcxx {

class Core final {
    Core(const Core&) = delete;
    Core& operator=(const Core&) = delete;

    Core(Core&&) = delete;
    Core& operator=(Core&&) = delete;

    explicit Core();

public:
    ~Core();

    static auto init() -> std::unique_ptr<Core>;
};

}  // namespace glfwcxx
