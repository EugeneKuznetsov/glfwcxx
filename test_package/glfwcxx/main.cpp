#include <cstdlib>

#include <glfwcxx/Core.hpp>
#include <glfwcxx/Window.hpp>

auto main() -> int
{
    auto core = glfwcxx::Core::init();
    return EXIT_SUCCESS;
}
