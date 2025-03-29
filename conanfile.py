from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMakeDeps, CMakeToolchain, CMake


class TaplRecipe(ConanFile):
    name = "tapl"
    version = "0.1.0"
    license = "MPL v2"
    description = "C++ Implementation of the different chapters of `Types and Programming Languages` from Benjamin C. Pierce"
    url = "https://github.com/baptisteesteban/tapl"
    settings = "os", "compiler", "arch", "build_type"
    author = "Baptiste Esteban <baptiste.esteban@epita.fr>"
    topics = "programming-languages", "types"
    tool_requires = ("bison/3.8.2", "flex/2.6.4", "cmake/4.0.0-rc4", "ninja/1.12.1")
    test_requires = "gtest/1.16.0"

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
