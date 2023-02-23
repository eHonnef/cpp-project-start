#include <Config.hpp>
#include <fmt/core.h>
#include <sample/Example.hpp>
#include <stdlib.h>

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
  std::system("cat ./LICENSE");

  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  Dummy d = Dummy();
  d.PrintStuff();
  d.PrintVersion();
  return d.doSomething() ? 0 : -1;
}
