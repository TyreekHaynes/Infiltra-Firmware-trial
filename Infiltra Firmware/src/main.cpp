#include <Arduino.h>
#include <Wire.h>
#include <TFT_eSPI.h>

#include "UserInterface/menus/menu_enums.h"
#include "UserInterface/bitmaps/menu_bitmaps.h"
#include "UserInterface/menus/menu_submenus.h"
#include "UserInterface/menus/submenu_options.h"
#include "Modules/Core/buttons.h"
#include "Modules/Functions/stopwatch.h"
#include "Modules/Core/Passlock.h"

// ---------- Board selection & rotation ----------
#if defined(M5CARDPUTER)
  #include <M5Cardputer.h>
  static constexpr uint8_t ROT_TOP = 4;

#elif defined(M5STICK_C_PLUS_2)
  #include <M5StickCPlus2.h>
  static constexpr uint8_t ROT_TOP = 2;

// --- StickC Plus 1.1: own path (no M5 display headers) ---
#elif defined(M5STICK_C_PLUS_1_1)
  static constexpr uint8_t ROT_TOP = 2;

#else
  // Fallback to Plus 2 style init if nothing else is defined
  #include <M5StickCPlus2.h>
  static constexpr uint8_t ROT_TOP = 2;
#endif

// Some projects define TFT_BL/logic in board JSON; guard them here.
#ifndef TFT_BL
  #define TFT_BL 27
#endif
#ifndef TFT_BACKLIGHT_ON
  #define TFT_BACKLIGHT_ON 1
#endif

// ---------- Shared TFT instance ----------
TFT_eSPI tft;

// ---------- App state ----------
bool inOptionScreen = false;
bool inStopwatch    = false;
bool inBGone        = false;
bool inIRRead       = false;
bool inWiFiScan     = false;
bool inPacketScan   = false;
MenuState currentMenu = WIFI_MENU;

// =====================================================================
//                 StickC Plus 1.1 (AXP192) Power Bring-up
// =====================================================================
#if defined(M5STICK_C_PLUS_1_1)
// AXP192 is on I2C addr 0x34. StickC family I2C pins are typically SDA=21, SCL=22.
static inline void axpWrite(uint8_t reg, uint8_t val) {
  Wire.beginTransmission(0x34);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

// Minimal rails/backlight enable for LCD on StickC Plus 1.1:
// - Enable DCDC1 (3V3), LDO2 (LCD backlight), LDO3 (LCD logic).
// - Set LDO2/LDO3 voltage to ~2.8–3.0V (tweak if you need brighter BL).
static void axp192_init_for_stickc_plus11() {
  Wire.begin(21, 22);

  // 0x12: Power output control
  // Bit mask used here enables DCDC1 + LDO2 + LDO3 (0b0100_1101 = 0x4D).
  axpWrite(0x12, 0x4D);

  // 0x28: LDO2/LDO3 voltage (high nibble=LDO2, low nibble=LDO3), ~100mV steps
  // 0xCC ~= 2.8V/2.8V; you can bump the backlight (LDO2) a step or two if too dim (e.g., 0xDC).
  axpWrite(0x28, 0xCC);

  delay(10);

  // If your hardware routes BL to a GPIO as well, handle it; otherwise ignore.
  #if (defined(TFT_BL) && (TFT_BL >= 0))
    pinMode(TFT_BL, OUTPUT);
    #if TFT_BACKLIGHT_ON
      digitalWrite(TFT_BL, HIGH);
    #else
      digitalWrite(TFT_BL, LOW);
    #endif
  #endif
}
#endif // M5STICK_C_PLUS_1_1

// =====================================================================
//                               setup()
// =====================================================================
void setup() {
#if defined(M5CARDPUTER)
  // Cardputer: use its power bring-up, but still render with our shared TFT
  M5Cardputer.begin();
  M5Cardputer.Display.setRotation(ROT_TOP);
  M5Cardputer.Display.setBrightness(180);

#elif defined(M5STICK_C_PLUS_2)
  // Plus 2: M5 lib handles AXP/backlight rails
  M5.begin();
  M5.Display.setRotation(ROT_TOP);
  M5.Display.setBrightness(200);

#elif defined(M5STICK_C_PLUS_1_1)
  // Plus 1.1: NO M5 display headers — we bring up power ourselves
  axp192_init_for_stickc_plus11();

#else
  // Fallback (treat like Plus 2)
  M5.begin();
  M5.Display.setRotation(ROT_TOP);
  M5.Display.setBrightness(200);
#endif

  // Common TFT init
  tft.init();
  tft.setRotation(ROT_TOP);
  tft.fillScreen(TFT_BLACK);
  delay(80);

  // App init
  initButtons();
  initSubmenuOptions(&tft);

  Core::Passlock::begin();
  Core::Passlock::promptForUnlock();

  // Optional quick color test if you still see black:
  // tft.fillScreen(TFT_RED); delay(200);
  // tft.fillScreen(TFT_GREEN); delay(200);
  // tft.fillScreen(TFT_BLUE); delay(200);

  drawWiFiMenu();
}

// =====================================================================
//                               loop()
// =====================================================================
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
