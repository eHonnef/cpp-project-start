#pragma once

/**
 * This is a dummy class to demonstrate features of the boiler plate.
 */
class Dummy {
private:
  int m_nValue;

public:
  /**
   * Default constructor for Dummy.
   */
  Dummy(int nValue);
  /**
   * Returns a bool.
   * @return Always True.
   */
  bool doSomething();

  /**
   * @brief Print stuff
   *
   */
  void PrintStuff();

  /**
   * @brief Print version
   *
   */
  void PrintVersion();

  /**
   * @brief      A header implemented function.
   * @return     An integer.
   */
  int HeaderImplemented() { return m_nValue; }
};
