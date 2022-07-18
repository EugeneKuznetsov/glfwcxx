#pragma once

#include <functional>
#include <memory>
#include <set>
#include <string>

#include <glfwcxx/KeyboardInput.hpp>
#include <glfwcxx/WindowHints.hpp>
#include <glfwcxx/WindowProperties.hpp>

namespace glfwcxx {

class Window final {
    class WindowDetails;

    using keyboard_callback_t = std::function<void(input::KeyboardKey, input::KeyboardAction, std::set<input::KeyboardKeyModifier>)>;
    using window_size_callback_t = std::function<void(const WindowSize&)>;
    using frame_buffer_size_callback_t = std::function<void(const FrameBufferSize&)>;
    using window_content_scale_callback_t = std::function<void(const WindowContentScale&)>;

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
    auto close() -> void;

public:
    auto should_close() const -> bool;
    auto window_size() const -> WindowSize;
    auto frame_buffer_size() const -> FrameBufferSize;
    auto window_content_scale() const -> WindowContentScale;

public:
    auto keyboard_input(const keyboard_callback_t& callback) -> void;
    auto window_size(const window_size_callback_t& callback) -> void;
    auto frame_buffer_size(const frame_buffer_size_callback_t& callback) -> void;
    auto window_content_scale(const window_content_scale_callback_t& callback) -> void;

private:
    static auto setup_boolean_window_hints(const WindowHints& hints) -> void;
    static auto setup_numeric_window_hints(const WindowHints& hints) -> void;
    static auto setup_string_window_hints(const WindowHints& hints) -> void;
    static auto setup_preset_window_hints(const WindowHints& hints) -> void;

private:
    std::unique_ptr<WindowDetails> window_;
};

}  // namespace glfwcxx
