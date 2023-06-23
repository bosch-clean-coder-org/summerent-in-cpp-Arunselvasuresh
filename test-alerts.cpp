#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("Temperature Breach Classification - Passive Cooling") {
  BatteryCharacter batteryChar{PASSIVE_COOLING};

  SECTION("Temperature within limits") {
    double temperature = 25.0;
    REQUIRE(classifyTemperatureBreach(batteryChar.coolingType, temperature) == NORMAL);
  }

  SECTION("Temperature too low") {
    double temperature = -5.0;
    REQUIRE(classifyTemperatureBreach(batteryChar.coolingType, temperature) == TOO_LOW);
  }

  SECTION("Temperature too high") {
    double temperature = 40.0;
    REQUIRE(classifyTemperatureBreach(batteryChar.coolingType, temperature) == TOO_HIGH);
  }
}

TEST_CASE("Temperature Breach Classification - Hi-Active Cooling") {
  BatteryCharacter batteryChar{HI_ACTIVE_COOLING};

  SECTION("Temperature within limits") {
    double temperature = 35.0;
    REQUIRE(classifyTemperatureBreach(batteryChar.coolingType, temperature) == NORMAL);
  }

  SECTION("Temperature too low") {
    double temperature = -10.0;
    REQUIRE(classifyTemperatureBreach(batteryChar.coolingType, temperature) == TOO_LOW);
  }

  SECTION("Temperature too high") {
    double temperature = 50.0;
    REQUIRE(classifyTemperatureBreach(batteryChar.coolingType, temperature) == TOO_HIGH);
  }
}


