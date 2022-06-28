#pragma once

namespace glfwcxx {

class CoreInitHints {
public:
    auto with_joystick_hat_buttons() -> CoreInitHints&;
    auto with_cocoa_chdir_resources() -> CoreInitHints&;
    auto with_cocoa_menubar() -> CoreInitHints&;

    inline constexpr auto joystick_hat_buttons() const -> bool { return joystick_hat_buttons_; }
    inline constexpr auto cocoa_chdir_resources() const -> bool { return cocoa_chdir_resources_; }
    inline constexpr auto cocoa_menubar() const -> bool { return cocoa_menubar_; }

private:
    bool joystick_hat_buttons_{false};
    bool cocoa_chdir_resources_{false};
    bool cocoa_menubar_{false};
};

}  // namespace glfwcxx
