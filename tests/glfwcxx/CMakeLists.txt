add_test_suite(GLFWCXX_TEST_SUITE_NAME test_Core PRIVATE_DEPENDENCY_TARGETS glfwcxx::core-stub)
add_test_suite(GLFWCXX_TEST_SUITE_NAME test_Common PRIVATE_DEPENDENCY_TARGETS glfwcxx::common-stub)
add_test_suite(GLFWCXX_TEST_SUITE_NAME test_Window PRIVATE_DEPENDENCY_TARGETS glfwcxx::window-stub
               glfwstub)
