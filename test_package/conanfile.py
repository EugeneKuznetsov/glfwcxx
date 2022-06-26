from conans import ConanFile, CMake
from pathlib import Path

class GLFWCXXConsumer(ConanFile):
    name = "glfwcxx-consumer"
    author = "Eugene Kuznetsov"
    license = "MIT"
    generators = "cmake_find_package"
    settings = "os", "compiler", "arch", "build_type"
    tool_requires = "cmake/[>3.20.x]", "ninja/[^1.11.x]", "gtest/[~1.11.x]"

    def build(self):
        self.cmake.build()

    def test(self):
        glfwcxxapp = self._path_to_binary("glfwcxxapp")
        glfwcxxstubapp = self._path_to_binary("glfwcxxstubapp")
        self.run(glfwcxxapp, run_environment=True)
        self.run(glfwcxxstubapp, run_environment=True)

    def _path_to_binary(self, name):
        binary = str(Path("bin") / name)
        if self.settings.os == "Windows":
            binary += ".exe"
        return binary
    
    @property
    def cmake(self):
        if not hasattr(self, "_cmake"):
            self._cmake = CMake(self, generator="Ninja")
            self._cmake.configure()
        return self._cmake
