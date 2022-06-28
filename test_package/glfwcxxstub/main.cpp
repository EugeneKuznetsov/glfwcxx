#include <cstdlib>
#include <stdexcept>

#include <glfwcxx/Core.hpp>

auto main() -> int
{
    glfwcxx::CoreStub::init_failure();
    try {
        auto glfw = glfwcxx::Core::init();
    }
    catch (const std::runtime_error&) {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
