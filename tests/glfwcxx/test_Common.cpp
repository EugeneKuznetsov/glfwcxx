#include <tuple>
#include <utility>

#include <gtest/gtest.h>

#include "glfwcxx/Common.hpp"
#include <glfwcxx/CommonStub.hpp>

class glfwcxx_common_errors
    : public testing::TestWithParam<std::tuple<std::pair<int, std::string>, std::pair<glfwcxx::Error, std::string>>> {
public:
    auto SetUp() -> void { glfwcxx::CommonStub::reset(); }
};

static constexpr int GLFW_NO_ERROR = 0;
static constexpr int GLFW_NOT_INITIALIZED = 0x00010001;
static constexpr int GLFW_NO_CURRENT_CONTEXT = 0x00010002;
static constexpr int GLFW_INVALID_ENUM = 0x00010003;
static constexpr int GLFW_INVALID_VALUE = 0x00010004;
static constexpr int GLFW_OUT_OF_MEMORY = 0x00010005;
static constexpr int GLFW_API_UNAVAILABLE = 0x00010006;
static constexpr int GLFW_VERSION_UNAVAILABLE = 0x00010007;
static constexpr int GLFW_PLATFORM_ERROR = 0x00010008;
static constexpr int GLFW_FORMAT_UNAVAILABLE = 0x00010009;
static constexpr int GLFW_NO_WINDOW_CONTEXT = 0x0001000A;

const auto glfwcxx_common_errors_test_values = testing::Values(
    std::make_tuple(std::make_pair(GLFW_NO_ERROR, ""), std::make_pair(glfwcxx::Error::NO_ERROR, "")),
    std::make_tuple(std::make_pair(GLFW_NOT_INITIALIZED, "err1"), std::make_pair(glfwcxx::Error::NOT_INITIALIZED, "err1")),
    std::make_tuple(std::make_pair(GLFW_NO_CURRENT_CONTEXT, "err2"), std::make_pair(glfwcxx::Error::NO_CURRENT_CONTEXT, "err2")),
    std::make_tuple(std::make_pair(GLFW_INVALID_ENUM, "err3"), std::make_pair(glfwcxx::Error::INVALID_ENUM, "err3")),
    std::make_tuple(std::make_pair(GLFW_INVALID_VALUE, "err4"), std::make_pair(glfwcxx::Error::INVALID_VALUE, "err4")),
    std::make_tuple(std::make_pair(GLFW_OUT_OF_MEMORY, "err5"), std::make_pair(glfwcxx::Error::OUT_OF_MEMORY, "err5")),
    std::make_tuple(std::make_pair(GLFW_API_UNAVAILABLE, "err6"), std::make_pair(glfwcxx::Error::API_UNAVAILABLE, "err6")),
    std::make_tuple(std::make_pair(GLFW_VERSION_UNAVAILABLE, "err7"), std::make_pair(glfwcxx::Error::VERSION_UNAVAILABLE, "err7")),
    std::make_tuple(std::make_pair(GLFW_PLATFORM_ERROR, "err8"), std::make_pair(glfwcxx::Error::PLATFORM_ERROR, "err8")),
    std::make_tuple(std::make_pair(GLFW_FORMAT_UNAVAILABLE, "err9"), std::make_pair(glfwcxx::Error::FORMAT_UNAVAILABLE, "err9")),
    std::make_tuple(std::make_pair(GLFW_NO_WINDOW_CONTEXT, "err10"), std::make_pair(glfwcxx::Error::NO_WINDOW_CONTEXT, "err10")));

INSTANTIATE_TEST_SUITE_P(, glfwcxx_common_errors, glfwcxx_common_errors_test_values);

TEST_P(glfwcxx_common_errors, get_last_error_returns_error_when_something_bad_had_happened)
{
    const auto [actual_error, expected_error] = GetParam();
    glfwcxx::CommonStub::set_error(actual_error.first, actual_error.second);

    const auto last_error = glfwcxx::get_last_error();
    EXPECT_EQ(last_error.first, expected_error.first);
    EXPECT_EQ(last_error.second, expected_error.second);
}

TEST(glfwcxx_common, get_last_error_returns_no_error_when_nothing_bad_had_happened)
{
    glfwcxx::CommonStub::reset();
    const auto last_error = glfwcxx::get_last_error();
    EXPECT_EQ(last_error.first, glfwcxx::Error::NO_ERROR);
    EXPECT_EQ(last_error.second, "");
}
