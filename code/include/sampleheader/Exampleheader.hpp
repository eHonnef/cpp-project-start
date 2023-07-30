#pragma once

#include <Config.hpp>
#include <fmt/core.h>
#include <units.h>

/**
 * This is a dummy class to demonstrate features of the boiler plate.
 */
class DummyHeader {
private:
  int m_nValue;

public:
  /**
   * Default constructor for Dummy.
   */
  DummyHeader(int nValue) { m_nValue = nValue; }

  /**
   * Returns a bool.
   * @return Always True.
   */
  bool doSomething() {
    // Do silly things, using some C++17 features to enforce C++17 builds only.
    constexpr int digits[2] = {0, 1};
    auto [zero, one] = digits;
    return zero + one;
  }

  /**
   * @brief Print stuff
   *
   */
  void PrintStuff() {
    int nCelsius = this->HeaderImplemented();
    auto nKelvin =
        units::convert<units::temperature::celsius, units::temperature::kelvin>(
            nCelsius);
    fmt::print("{}ª Celsius is {} kelvins\n", nCelsius, nKelvin);
  }

  /**
   * @brief Print version
   *
   */
  void PrintVersion() {
    fmt::print("C++ Project starter v{}.{}.{}.{}\n", PROJECT_VERSION_MAJOR,
               PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH,
               PROJECT_VERSION_TWEAK);
  }

  /**
   * @brief      A header implemented function.
   * @return     An integer.
   */
  int HeaderImplemented() { return m_nValue; }
};
