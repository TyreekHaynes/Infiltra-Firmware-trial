#include <Arduino.h>
#include "core/config.h"
#include "core/system.h"
#include "network/ap.h"

#ifdef M5STICK
  #ifdef M5STICK_1
    #include <M5StickCPlus.h>
  #else
    #include <M5StickCPlus2.h>
  #endif
#endif

#ifdef CARDPUTER
  #include <M5Cardputer.h>
#endif

void setup() {
    delay(500);
    initSystem();
    setupAP();
    beep(POWER_ON_BEEPS);
}

void loop() {
    loopAP();
    
    #if defined(M5STICK) || defined(CARDPUTER)
    M5.update();
    #endif
    
    delay(5);
}
