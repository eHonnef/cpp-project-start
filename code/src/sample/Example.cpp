#include <Config.hpp>
#include <fmt/core.h>
#include <sample/Example.hpp>
#include <units.h>
#include <vector>

Dummy::Dummy(int nValue) { m_nValue = nValue; }

bool Dummy::doSomething() {
  // Do silly things, using some C++17 features to enforce C++17 builds only.
  constexpr int digits[2] = {0, 1};
  auto [zero, one] = digits;
  return zero + one;
}

void Dummy::PrintStuff() {
  int nCelsius = this->HeaderImplemented();
  auto nKelvin =
      units::convert<units::temperature::celsius, units::temperature::kelvin>(
          nCelsius);
  fmt::print("{}ª Celsius is {} kelvins\n", nCelsius, nKelvin);
}

void Dummy::PrintVersion() {
  fmt::print("C++ Project starter v{}.{}.{}.{}\n", PROJECT_VERSION_MAJOR,
             PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH,
             PROJECT_VERSION_TWEAK);
}
