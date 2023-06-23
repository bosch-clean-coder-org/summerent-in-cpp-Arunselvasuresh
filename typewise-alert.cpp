#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if (value < lowerLimit) {
    return TOO_LOW;
  }
  if (value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  const TemperatureLimits limits = temperatureLimits[coolingType];
  return inferBreach(temperatureInC, limits.lowerLimit, limits.upperLimit);
}

void sendAlert(const char* recepient, const char* message) {
  printf("To: %s\n", recepient);
  printf("%s\n", message);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  switch (alertTarget) {
    case TO_CONTROLLER:
      sendAlert("Controller", "Breach Detected");
      break;
    case TO_EMAIL:
      if (breachType != NORMAL) {
        const char* message = (breachType == TOO_LOW) ? "Temperature is too low" : "Temperature is too high";
        sendAlert("a.b@c.com", message);
      }
      break;
  }
}
