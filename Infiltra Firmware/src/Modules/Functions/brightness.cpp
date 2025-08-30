#include "brightness.h"
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

#ifndef TFT_BL
  #define TFT_BL 27
#endif
#ifndef TFT_BACKLIGHT_ON
  #define TFT_BACKLIGHT_ON 1   
#endif

static constexpr uint8_t ROT_ALT = (ROT_TOP + 1) & 0x3;
static bool sFrameDrawn=false;
static bool sDirty=true;
static int  sPct = 70; 

static void applyBrightness(int pct){
  if (pct<0) pct=0; if (pct>100) pct=100;
  uint8_t hw = (uint8_t)((pct * 255) / 100);
#if defined(M5CARDPUTER)
  M5Cardputer.Display.setBrightness(hw);
#elif defined(M5STICK_C_PLUS_2)
  M5.Lcd.setBrightness(hw);
#elif defined(M5STICK_C_PLUS_1_1)
  static bool sPwmInit = false;
  if (!sPwmInit) {
    ledcAttachPin(TFT_BL, 1);    
    ledcSetup(1, 12000, 8);      
    sPwmInit = true;
  }
  #if TFT_BACKLIGHT_ON
    ledcWrite(1, hw);
  #else
    ledcWrite(1, 255 - hw);
  #endif
#else
  
  M5.Lcd.setBrightness(hw);
#endif
}

void brightnessReset(){
  sFrameDrawn=false;
  sDirty=true;
  sPct = 70;
  applyBrightness(sPct);
}

static void drawFrame(TFT_eSPI& tft){
  tft.setRotation(ROT_ALT);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextDatum(TC_DATUM);
  tft.drawString("Brightness", tft.width()/2, 6, 2);
  tft.drawRoundRect(10, 30, tft.width()-20, 20, 4, TFT_DARKGREY);
  sFrameDrawn = true;
  sDirty = true;
}

static void drawSlider(TFT_eSPI& tft){
  int w = tft.width()-20;
  int x = 10;
  int y = 30;
  int fillw = (w * sPct) / 100;
  tft.fillRoundRect(x+1, y+1, w-2, 18, 3, TFT_BLACK);
  tft.fillRoundRect(x+1, y+1, fillw-2, 18, 3, TFT_WHITE);
  tft.setTextDatum(TR_DATUM);
  tft.drawString(String(sPct) + "%", tft.width()-8, 56, 2);
}

void brightnessDrawScreen(TFT_eSPI& tft){
  if (!sFrameDrawn) drawFrame(tft);
  if (sDirty) {
    sDirty = false;
    drawSlider(tft);
  }
}

void brightnessHandleInput(bool a, bool b, bool c, bool& requestExit){
  requestExit = false;
  if (b) { sPct += 5; if (sPct>100) sPct=100; applyBrightness(sPct); sDirty=true; }
  if (c) { sPct -= 5; if (sPct<0)   sPct=0;   applyBrightness(sPct); sDirty=true; }
  if (a) { requestExit = true; sFrameDrawn=false; }
}
