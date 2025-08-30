#include <Arduino.h>

#if defined(M5CARDPUTER)
  #include <M5Cardputer.h>
  static constexpr uint8_t ROT_TOP = 4;
#elif defined(M5STICK_C_PLUS_2)
  #include <M5StickCPlus2.h>
  static constexpr uint8_t ROT_TOP = 2;
#elif defined(M5STICK_C_PLUS_1_1)
  static constexpr uint8_t ROT_TOP = 2;
#else
  #include <M5StickCPlus2.h>
  static constexpr uint8_t ROT_TOP = 2;
#endif
#include <TFT_eSPI.h>
#include "UserInterface/menus/menu_enums.h"
#include "UserInterface/bitmaps/menu_bitmaps.h"
#include "UserInterface/menus/menu_submenus.h"
#include "UserInterface/menus/submenu_options.h"
#include "Modules/Core/buttons.h"
#include "Modules/Functions/stopwatch.h"
#ifndef TFT_BL
  #define TFT_BL 27
#endif
#ifndef TFT_BACKLIGHT_ON
  #define TFT_BACKLIGHT_ON 1   
#endif

TFT_eSPI tft;
bool inOptionScreen = false;
bool inStopwatch    = false;
bool inBGone        = false;
bool inIRRead       = false;
bool inWiFiScan     = false;   
bool inPacketScan   = false;   
MenuState currentMenu = WIFI_MENU;

void setup() {
#if defined(M5CARDPUTER)
  M5Cardputer.begin();
  M5Cardputer.Display.setRotation(ROT_TOP);
  M5Cardputer.Display.setBrightness(180);
#elif defined(M5STICK_C_PLUS_2)
  M5.begin();
  M5.Display.setRotation(ROT_TOP);
  M5.Display.setBrightness(200);
#elif defined(M5STICK_C_PLUS_1_1)
  pinMode(TFT_BL, OUTPUT);
  #if TFT_BACKLIGHT_ON
    digitalWrite(TFT_BL, HIGH);
  #else
    digitalWrite(TFT_BL, LOW);
  #endif
#else
  M5.begin();
  M5.Display.setRotation(ROT_TOP);
  M5.Display.setBrightness(200);
#endif

  tft.init();
  tft.setRotation(ROT_TOP);
  tft.fillScreen(TFT_BLACK);
  delay(100);
  initButtons();
  initSubmenuOptions(&tft);
  drawWiFiMenu();
}

void loop() {
  updateButtons();
  handleAllButtonLogic(&tft,
                       inOptionScreen,
                       inStopwatch,
                       inBGone,
                       inIRRead,
                       inWiFiScan,
                       inPacketScan,
                       currentMenu);
  
}
