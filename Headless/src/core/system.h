#ifndef CORE_SYSTEM_H
#define CORE_SYSTEM_H

#include <Arduino.h>

#ifndef BEEP_PIN
  #define BEEP_PIN 2
#endif
#ifndef BEEP_DURATION
  #define BEEP_DURATION 200
#endif
#ifndef BEEP_PAUSE
  #define BEEP_PAUSE 100
#endif
#ifndef POWER_ON_BEEPS
  #define POWER_ON_BEEPS 2
#endif
#ifndef POWER_OFF_BEEPS
  #define POWER_OFF_BEEPS 3
#endif

void initSystem();
void beep(int count);
void powerOff();
void disableDisplay();
bool isM5StickCPlus1();
String getDeviceType();

#endif
