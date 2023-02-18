#include <Config.hpp>
#include <fmt/core.h>
#include <sample/Example.hpp>
#include <stdlib.h>

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
  fmt::print("C++ Project starter v{}.{}.{}.{}\n", PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR,
             PROJECT_VERSION_PATCH, PROJECT_VERSION_TWEAK);
  std::system("cat ./LICENSE");

  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  Dummy d = Dummy();
  d.PrintStuff();
  return d.doSomething() ? 0 : -1;
}
