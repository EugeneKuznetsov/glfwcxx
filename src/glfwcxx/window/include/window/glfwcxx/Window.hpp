#pragma once

#include <memory>
#include <string>

#include <glfwcxx/WindowHints.hpp>

#ifdef GLFWCXX_STUB
#include <glfwcxx/WindowStub.hpp>
#endif

struct GLFWwindow;

namespace glfwcxx {

struct WindowSize {
    int width;
    int height;
};

class Window {
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;

    explicit Window(const WindowSize& size, const std::string& title);

public:
    [[nodiscard]] static auto create_window(const WindowSize& size, const std::string& title) -> std::unique_ptr<Window>;
    [[nodiscard]] static auto create_window(const WindowSize& size, const std::string& title, const WindowHints& hints)
        -> std::unique_ptr<Window>;

public:
    auto make_context_current() -> void;

private:
#ifdef __linux__
    using Deleter = void (*)(GLFWwindow*);
#else
    using Deleter = void(__cdecl&)(GLFWwindow*);
#endif
    std::unique_ptr<GLFWwindow, Deleter> window_;
    static const WindowHints default_window_hints_;
};

}  // namespace glfwcxx
