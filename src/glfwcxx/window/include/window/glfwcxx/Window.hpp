#pragma once

#include <memory>
#include <string>

#include <glfwcxx/WindowHints.hpp>

namespace glfwcxx {

class Window final {
    class WindowDetails;

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&&) = delete;
    Window& operator=(Window&&) = delete;

    explicit Window(const WindowSize& size, const std::string& title);

public:
    ~Window();

public:
    [[nodiscard]] static auto create_window(const WindowSize& size, const std::string& title) -> std::unique_ptr<Window>;
    [[nodiscard]] static auto create_window(const WindowSize& size, const std::string& title, const WindowHints& hints)
        -> std::unique_ptr<Window>;

public:
    auto make_context_current() -> void;
    auto poll_events() -> void;
    auto swap_buffers() -> void;

public:
    auto should_close() const -> bool;

private:
    std::unique_ptr<WindowDetails> window_;
    static const WindowHints default_window_hints_;
};

}  // namespace glfwcxx
