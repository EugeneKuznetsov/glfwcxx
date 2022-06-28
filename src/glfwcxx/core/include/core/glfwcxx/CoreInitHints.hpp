#pragma once

namespace glfwcxx {

struct CoreInitHints {
    bool joystick_hat_buttons{false};
    bool cocoa_chdir_resources{false};
    bool cocoa_menubar{false};

    auto with_joystick_hat_buttons() -> CoreInitHints&;
    auto with_cocoa_chdir_resources() -> CoreInitHints&;
    auto with_cocoa_menubar() -> CoreInitHints&;
};

}  // namespace glfwcxx
