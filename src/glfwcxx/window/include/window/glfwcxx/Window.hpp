#pragma once

#include <memory>
#include <string>

#include <glfwcxx/WindowHints.hpp>

#ifdef GLFWCXX_STUB
#include <glfwcxx/WindowStub.hpp>
#endif

namespace glfwcxx {

struct WindowSize {
    int width;
    int height;
};

class Window {
public:
    static auto create_window(const WindowSize& size, const std::string& title) -> std::unique_ptr<Window>;
    static auto create_window(const WindowSize& size, const std::string& title, const WindowHints& hints) -> std::unique_ptr<Window>;

public:
    auto make_context_current() -> void;
};

}  // namespace glfwcxx
