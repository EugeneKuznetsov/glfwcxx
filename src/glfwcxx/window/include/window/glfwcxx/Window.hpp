#pragma once

#include <functional>
#include <memory>
#include <string>

#include <glfwcxx/WindowHints.hpp>

namespace glfwcxx {

namespace input {

enum class KeyboardKeys { ESCAPE };

enum class KeyboardActions { PRESS };

}  // namespace input

class Window final {
    class WindowDetails;

    using keyboard_callback_t = std::function<void(input::KeyboardKeys, input::KeyboardActions)>;

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

public:
    auto keyboard_input(const keyboard_callback_t& callback) -> void;

private:
    static auto setup_boolean_window_hints(const WindowHints& hints) -> void;
    static auto setup_numeric_window_hints(const WindowHints& hints) -> void;
    static auto setup_string_window_hints(const WindowHints& hints) -> void;
    static auto setup_preset_window_hints(const WindowHints& hints) -> void;

private:
    std::unique_ptr<WindowDetails> window_;
    static const WindowHints default_window_hints_;
};

}  // namespace glfwcxx
