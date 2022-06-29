cmake_minimum_required(VERSION 3.20)

project(
    glfwcxx
    VERSION 1.1.0
    LANGUAGES CXX)

include(BuildSettings)
include(CompilerSettings)
include(Packages)
include(GNUInstallDirs)
include(GenerateExportHeader)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
