#pragma once

namespace glfwcxx {

namespace input {
enum class KeyboardKey;
enum class KeyboardKeyModifier;
enum class KeyboardAction;
}  // namespace input

namespace helpers {

auto glfw_keyboard_key(const input::KeyboardKey& key) -> int;
auto glfw_keyboard_action(const input::KeyboardAction& action) -> int;
auto glfw_keyboard_modifier(const input::KeyboardKeyModifier& modifier) -> int;

auto glfwcxx_keyboard_key(int key) -> input::KeyboardKey;
auto glfwcxx_keyboard_action(int action) -> input::KeyboardAction;

}  // namespace helpers

}  // namespace glfwcxx
