function(add_test_suite)
    set(options)
    set(oneValueArgs GLFWCXX_TEST_SUITE_NAME)
    set(multiValueArgs PRIVATE_DEPENDENCY_TARGETS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(GLFWCXX_TARGET ${ARG_GLFWCXX_TEST_SUITE_NAME})

    add_executable(${GLFWCXX_TARGET} "${GLFWCXX_TARGET}.cpp")
    target_link_libraries(${GLFWCXX_TARGET} PRIVATE GTest::gtest_main)
    foreach(DEPENDENCY_TARGET IN LISTS ARG_PRIVATE_DEPENDENCY_TARGETS)
        target_link_libraries(${GLFWCXX_TARGET} PRIVATE $<BUILD_INTERFACE:${DEPENDENCY_TARGET}>)
    endforeach()

    add_test(NAME ${GLFWCXX_TARGET} COMMAND $<TARGET_FILE:${GLFWCXX_TARGET}>)
endfunction()
