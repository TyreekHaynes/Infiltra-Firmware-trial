#include "system.h"
#include "config.h"

#ifdef M5STICK_1
  #ifdef M5STICK_2
    #include <M5StickCPlus.h>
  #else
    #include <M5StickCPlus2.h>
  #endif
#endif

#ifdef CARDPUTER
  #include <M5Cardputer.h>
#endif

bool isM5StickCPlus1() {
#ifdef M5STICK_2
    return true;
#else
    return false;
#endif
}

void initSystem() {
#ifdef M5STICK_1
    M5.begin();
#endif

#ifdef CARDPUTER
    M5.begin();
#endif

    pinMode(BEEP_PIN, OUTPUT);
    disableDisplay();
}

void disableDisplay() {
#ifdef M5STICK_1
  #ifdef M5STICK_2
    M5.Lcd.fillScreen(TFT_BLACK);
  #else
    M5.Lcd.sleep();
  #endif
#endif

#ifdef CARDPUTER
    M5.Display.sleep();
#endif

#ifdef LILYGO_T_EMBED
#endif
}
void beep(int count) {
    if (deviceSettings.disableBeep) {
        return;
    }
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < BEEP_DURATION; j++) {
            digitalWrite(BEEP_PIN, HIGH);
            delayMicroseconds(250);
            digitalWrite(BEEP_PIN, LOW);
            delayMicroseconds(250);
        }
        
        if (i < count - 1) {
            delay(BEEP_PAUSE);
        }
    }
}

void powerOff() {
    beep(POWER_OFF_BEEPS);
    
#ifdef M5STICK_1
  #ifdef M5STICK_2
    M5.Axp.PowerOff();
  #else
    M5.Power.powerOff();
  #endif
#endif

#ifdef CARDPUTER
    M5.Power.powerOff();
#endif
}
