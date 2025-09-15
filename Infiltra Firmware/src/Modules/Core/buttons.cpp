#include "buttons.h"
#if defined(M5CARDPUTER)
  #include <M5Cardputer.h>
  static constexpr uint8_t ROT_TOP = 4;
#else
  #include <M5StickCPlus2.h>
  static constexpr uint8_t ROT_TOP = 2;
#endif
#include <Arduino.h>
#include "././UserInterface/bitmaps/menu_bitmaps.h"
#include "././UserInterface/menus/menu_submenus.h"
#include "././UserInterface/menus/submenu_options.h"
#include "././UserInterface/menus/menu_enums.h"
#include "././Modules/Functions/brightness.h"
#include "././Modules/Functions/stopwatch.h"
#include "././Modules/Functions/bgone.h"
#include "././Modules/Functions/ir_read.h"
#include "././Modules/Functions/wifi_scan.h"
#include "././Modules/Functions/packet_scan.h"
#include "././Modules/Functions/integrated_files.h"
#include "././Modules/Functions/rpi_connect_info.h"
#include "././Modules/Functions/web_files.h"
#include "././Modules/Functions/ble_scan.h"
#include "././Modules/Functions/ble_google_adv.h"
#include "././Modules/Core/Passlock.h"

#if defined(M5CARDPUTER)
#ifndef KEY_ENTER
#define KEY_ENTER 0x28
#endif
#ifndef KEY_SEMICOLON
#define KEY_SEMICOLON 0x33
#endif
#ifndef KEY_DOT
#define KEY_DOT 0x37
#endif
#ifndef KEY_BACKTICK
#define KEY_BACKTICK 0x35
#endif
#else
#ifndef BTN_C_PIN
#define BTN_C_PIN 35
#endif
#endif

static bool sAEdge=false, sBEdge=false, sCEdge=false, sExitEdge=false;
static bool sInBLEScan      = false;
static bool sInBLEGoogleAdv = false;
static bool sInBrightness   = false;
static bool sInIntegrated   = false;
static bool sInRpiInfo      = false;
static bool sInWebFiles     = false;

void initButtons() {
#if defined(M5CARDPUTER)
#else
  pinMode(BTN_C_PIN, INPUT_PULLUP);
#endif
}

void updateButtons() {
#if defined(M5CARDPUTER)
  M5Cardputer.update();
  static bool lastARaw=false, lastBRaw=false, lastCRaw=false, lastExitRaw=false;
  bool aRaw =
      M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER) ||
      M5Cardputer.Keyboard.isKeyPressed('\r');
  bool bRaw =
      M5Cardputer.Keyboard.isKeyPressed(';') ||
      M5Cardputer.Keyboard.isKeyPressed(KEY_SEMICOLON);
  bool cRaw =
      M5Cardputer.Keyboard.isKeyPressed('.') ||
      M5Cardputer.Keyboard.isKeyPressed(KEY_DOT);
  bool exitRaw =
      M5Cardputer.Keyboard.isKeyPressed('`') ||
      M5Cardputer.Keyboard.isKeyPressed(KEY_BACKTICK);

  sAEdge    = aRaw   && !lastARaw;
  sBEdge    = bRaw   && !lastBRaw;
  sCEdge    = cRaw   && !lastCRaw;
  sExitEdge = exitRaw&& !lastExitRaw;

  lastARaw = aRaw;
  lastBRaw = bRaw;
  lastCRaw = cRaw;
  lastExitRaw = exitRaw;
#else
  M5.update();
  sAEdge = M5.BtnA.wasPressed();
  sBEdge = M5.BtnB.wasPressed();
  static bool lastCRaw=false;
  bool cRaw = !digitalRead(BTN_C_PIN);
  sCEdge = cRaw && !lastCRaw;
  lastCRaw = cRaw;
  sExitEdge = false; 
#endif
}

bool btnAPressed(){ return sAEdge; }
bool btnBPressed(){ return sBEdge; }
bool btnCPressed(){ return sCEdge; }
static bool btnExitSpecialPressed(){ return sExitEdge; }
void finalizeButtons() { }

static String norm(String s){
  s.toLowerCase();
  String r; r.reserve(s.length());
  for (size_t i=0;i<s.length();++i){
    char c = s[i];
    if ((c>='a'&&c<='z')||(c>='0'&&c<='9')) r += c;
  }
  return r;
}
static bool labelIsWifiScan(const String& label){
  String n = norm(label);
  if (n.indexOf("wifiscan")>=0) return true;
  if (n.indexOf("wifiscanner")>=0) return true;
  if (n.indexOf("wifinetworkscan")>=0) return true;
  return (n.indexOf("wifi")>=0 && (n.indexOf("scan")>=0 || n.indexOf("scanner")>=0));
}
static bool labelIsPacketScan(const String& label){
  String n = norm(label);
  if (n.indexOf("packetscan")>=0 || n.indexOf("packetscanner")>=0) return true;
  if (n.indexOf("pktscan")>=0 || n.indexOf("sniffer")>=0) return true;
  return ( (n.indexOf("packet")>=0 || n.indexOf("pkt")>=0 )
        && (n.indexOf("scan")>=0 || n.indexOf("sniff")>=0) );
}
static bool labelIsBLEScan(const String& label){
  String n = norm(label);
  bool hasBle = (n.indexOf("ble")>=0 || n.indexOf("bluetooth")>=0);
  bool hasScan = (n.indexOf("scan")>=0 || n.indexOf("scanner")>=0 || n.indexOf("discover")>=0);
  return hasBle && hasScan;
}
static bool labelIsBLEGoogleAdv(const String& label){
  String n = norm(label);
  if (n.indexOf("google")>=0) return true;
  if ((n.indexOf("ble")>=0 || n.indexOf("bluetooth")>=0) &&
      (n.indexOf("adv")>=0 || n.indexOf("advert")>=0 || n.indexOf("advertise")>=0))
    return true;
  return false;
}
static bool labelIsBrightness(const String& label){
  String n = norm(label);
  return (n.indexOf("bright")>=0 || n.indexOf("display")>=0);
}
static bool labelIsIntegrated(const String& label){
  String n = norm(label);
  return (n.indexOf("integrated")>=0);
}
static bool labelIsRpiInfo(const String& label){
  String n = norm(label);
  if (n == "info") return true;
  bool hasInfo = (n.indexOf("info") >= 0 || n.indexOf("about") >= 0 || n.indexOf("help") >= 0);
  bool hasRpi  = (n.indexOf("rpi") >= 0 || n.indexOf("raspberrypi") >= 0 || n.indexOf("raspberry") >= 0 || n.indexOf("pi") >= 0);
  bool hasConn = (n.indexOf("connect") >= 0);
  return hasInfo && (hasRpi || hasConn);
}
static bool labelIsPasslock(const String& label){
  String n = norm(label);
  return (n.indexOf("passlock")>=0 || n.indexOf("passkey")>=0 || n.indexOf("password")>=0);
}

static void handleSubmenuAction(
  MenuState currentMenu,
  int idx,
  TFT_eSPI* tft,
  bool& inStopwatch,
  bool& inOptionScreen,
  bool& inBGone,
  bool& inIRRead,
  bool& inWiFiScan,
  bool& inPacketScan
) {

  if (currentMenu == EXTRAS_SUBMENU && idx == 1) {
    resetStopwatch();
    drawStopwatchScreen(*tft);
    inStopwatch = true;
    return;
  }

  if (currentMenu == IR_SUBMENU && idx == 1) {
    bgoneReset();
    bgoneDrawScreen(*tft);
    inBGone = true;
    return;
  }

  if (currentMenu == IR_SUBMENU && idx == 4) {
    irReadReset();
    irReadDrawScreen(*tft);
    inIRRead = true;
    return;
  }

  if (currentMenu == WIFI_SUBMENU && idx > 0) {
    if (idx == 1) { wifiScanReset();   wifiScanDrawScreen(*tft);   inWiFiScan   = true; return; }
    if (idx == 2) { packetScanReset(); packetScanDrawScreen(*tft); inPacketScan = true; return; }
    String label = getSubmenuOptionText();
    if (labelIsPacketScan(label)) { packetScanReset(); packetScanDrawScreen(*tft); inPacketScan = true; return; }
    if (labelIsWifiScan(label))   { wifiScanReset();   wifiScanDrawScreen(*tft);   inWiFiScan   = true; return; }
  }

  if (currentMenu == BLUETOOTH_SUBMENU && idx > 0) {
    if (idx == 1) { bleScanReset();      bleScanDrawScreen(*tft);      sInBLEScan = true;      return; }
    if (idx == 2) { bleGoogleAdvReset(); bleGoogleAdvDrawScreen(*tft); sInBLEGoogleAdv = true; return; }
    String label = getSubmenuOptionText();
    if (labelIsBLEScan(label))        { bleScanReset();      bleScanDrawScreen(*tft);      sInBLEScan = true;      return; }
    if (labelIsBLEGoogleAdv(label))   { bleGoogleAdvReset(); bleGoogleAdvDrawScreen(*tft); sInBLEGoogleAdv = true; return; }
  }

  if (currentMenu == SETTINGS_SUBMENU && idx > 0) {
    String label = getSubmenuOptionText();
    if (labelIsBrightness(label)) {
      brightnessReset();
      brightnessDrawScreen(*tft);
      sInBrightness = true;
      return;
    }
    if (labelIsPasslock(label)) {
      Core::Passlock::runSettingsFlow();
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawSettingsSubmenu();
      delay(30);
      return;
    }
  }

  if (currentMenu == FILES_SUBMENU && idx > 0) {
    String label = getSubmenuOptionText();

    if (labelIsIntegrated(label) || idx == 2) {
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      integratedFilesReset();
      integratedFilesDrawScreen(*tft);
      sInIntegrated = true;
      return;
    }
  }

  if (currentMenu == RPI_SUBMENU && idx > 0) {
    String label = getSubmenuOptionText();
    if (labelIsRpiInfo(label)) {
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      rpiInfoReset();
      rpiInfoDrawScreen(*tft);
      sInRpiInfo = true;
      return;
    }
  }

#if defined(M5CARDPUTER)
  drawOptionsLayerBackground(*tft);
#endif
  inOptionScreen = true;
}

void handleAllButtonLogic(
  TFT_eSPI* tft,
  bool& inOptionScreen,
  bool& inStopwatch,
  bool& inBGone,
  bool& inIRRead,
  bool& inWiFiScan,
  bool& inPacketScan,
  MenuState& currentMenu
) {
  unsigned long now = millis();

  if (sInBLEGoogleAdv) {
    bool exitReq = false;
#if defined(M5CARDPUTER)
    bleGoogleAdvHandleInput(btnAPressed(), btnBPressed(),
                            btnCPressed() || btnExitSpecialPressed(), exitReq);
#else
    bleGoogleAdvHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
#endif
    if (exitReq) {
      sInBLEGoogleAdv = false;
      bleGoogleAdvStop();
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawBluetoothSubmenu();
      delay(30);
      return;
    }
    bleGoogleAdvDrawScreen(*tft);
    delay(30);
    return;
  }

  if (sInBLEScan) {
    bool exitReq = false;
#if defined(M5CARDPUTER)
    bleScanHandleInput(btnAPressed(), btnBPressed(),
                       btnCPressed() || btnExitSpecialPressed(), exitReq);
#else
    bleScanHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
#endif
    if (exitReq) {
      sInBLEScan = false;
      bleScanStop();
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawBluetoothSubmenu();
      delay(30);
      return;
    }
    bleScanDrawScreen(*tft);
    delay(30);
    return;
  }

  if (sInBrightness) {
    bool exitReq = false;
    brightnessHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
    if (exitReq) {
      sInBrightness = false;
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawSettingsSubmenu();
      delay(30);
      return;
    }
    brightnessDrawScreen(*tft);
    delay(30);
    return;
  }

  if (sInIntegrated) {
    bool exitReq = false;
    integratedFilesHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
    if (exitReq) {

      extern bool integratedFilesConsumeOpenWebRequest();
      if (integratedFilesConsumeOpenWebRequest()) {
        sInIntegrated = false;
        tft->fillScreen(TFT_BLACK);
        tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
        drawOptionsLayerBackground(*tft);
#endif
        webFilesReset();
        webFilesDrawScreen(*tft);
        sInWebFiles = true;
        delay(20);
        return;
      }

      sInIntegrated = false;
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawFilesSubmenu();
      delay(30);
      return;
    }
    integratedFilesDrawScreen(*tft);
    delay(30);
    return;
  }

  if (sInRpiInfo) {
    bool exitReq = false;
    rpiInfoHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
    if (exitReq) {
      sInRpiInfo = false;
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawRpiSubmenu();
      delay(20);
      return;
    }
    rpiInfoDrawScreen(*tft);
    delay(20);
    return;
  }

  if (sInWebFiles) {
    bool exitReq = false;
#if defined(M5CARDPUTER)
    webFilesHandleInput(btnAPressed(), btnBPressed(),
                        btnCPressed() || btnExitSpecialPressed(), exitReq);
#else
    webFilesHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
#endif
    if (exitReq) {
      sInWebFiles = false;
      webFilesStop();
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawFilesSubmenu();
      delay(30);
      return;
    }
    webFilesDrawScreen(*tft);
    delay(30);
    return;
  }

  if (inStopwatch) {
    bool exitReq = false;
#if defined(M5CARDPUTER)
    stopwatchHandleInput(btnAPressed(), btnBPressed(),
                         btnCPressed() || btnExitSpecialPressed(), exitReq);
#else
    stopwatchHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
#endif
    if (exitReq) {
      inStopwatch = false;
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawExtrasSubmenu();
      delay(20);
      return;
    }

    drawStopwatchTimeOnly(*tft);
    delay(20);
    return;
  }

  if (inWiFiScan) {
    bool exitReq = false;
#if defined(M5CARDPUTER)
    wifiScanHandleInput(btnAPressed(), btnBPressed(),
                        btnCPressed() || btnExitSpecialPressed(), exitReq);
#else
    wifiScanHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
#endif
    if (exitReq) {
      inWiFiScan = false;
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawWiFisubmenu();
      delay(30);
      return;
    }
    wifiScanDrawScreen(*tft);
    delay(30);
    return;
  }

  if (inPacketScan) {
    bool exitReq = false;
#if defined(M5CARDPUTER)
    packetScanHandleInput(btnAPressed(), btnBPressed(),
                          btnCPressed() || btnExitSpecialPressed(), exitReq);
#else
    packetScanHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
#endif
    if (exitReq) {
      inPacketScan = false;
      packetScanStop();
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawWiFisubmenu();
      delay(30);
      return;
    }
    packetScanDrawScreen(*tft);
    delay(30);
    return;
  }

  if (inIRRead) {
    bool exitReq = false;
#if defined(M5CARDPUTER)
    irReadHandleInput(btnAPressed(), btnBPressed(),
                      btnCPressed() || btnExitSpecialPressed(), exitReq);
#else
    irReadHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
#endif
    if (exitReq) {
      inIRRead = false;
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawIrSubmenu();
      delay(30);
      return;
    }
    irReadDrawScreen(*tft);
    delay(30);
    return;
  }

  if (inBGone) {
    bool exitReq = false;
    bgoneHandleInput(btnAPressed(), btnBPressed(), btnCPressed(), exitReq);
    if (exitReq) {
      inBGone = false;
      tft->fillScreen(TFT_BLACK);
      tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
      drawOptionsLayerBackground(*tft);
#endif
      drawIrSubmenu();
      delay(30);
      return;
    }
    bgoneDrawScreen(*tft);
    delay(30);
    return;
  }

  if (inOptionScreen && btnCPressed()) {
    inOptionScreen = false;
    tft->fillScreen(TFT_BLACK);
    tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
    drawOptionsLayerBackground(*tft);
#endif
    switch(currentMenu) {
      case WIFI_SUBMENU:       drawWiFisubmenu(); break;
      case BLUETOOTH_SUBMENU:  drawBluetoothSubmenu(); break;
      case IR_SUBMENU:         drawIrSubmenu(); break;
      case RF_SUBMENU:         drawRfSubmenu(); break;
      case NRF_SUBMENU:        drawNrfSubmenu(); break;
      case RADIO_SUBMENU:      drawRadioSubmenu(); break;
      case GPS_SUBMENU:        drawGpsSubmenu(); break;
      case RPI_SUBMENU:        drawRpiSubmenu(); break;
      case BADUSB_SUBMENU:     drawBadUsbSubmenu(); break;
      case SETTINGS_SUBMENU:   drawSettingsSubmenu(); break;
      case EXTRAS_SUBMENU:     drawExtrasSubmenu(); break;
      case FILES_SUBMENU:      drawFilesSubmenu(); break;
      case RFID_SUBMENU:       drawRfidSubmenu(); break;
      case NFC_SUBMENU:        drawNfcSubmenu(); break;
      default: break;
    }
    delay(10);
    return;
  }

  if (!inOptionScreen && !inStopwatch && !inIRRead && !inBGone &&
      !inWiFiScan && !inPacketScan && !sInBLEScan && !sInBLEGoogleAdv &&
      !sInBrightness && !sInIntegrated && !sInRpiInfo && !sInWebFiles) {
    switch(currentMenu) {
      case WIFI_SUBMENU: case BLUETOOTH_SUBMENU: case IR_SUBMENU:
      case RF_SUBMENU: case NRF_SUBMENU: case RADIO_SUBMENU:
      case GPS_SUBMENU: case RPI_SUBMENU: case BADUSB_SUBMENU:
      case SETTINGS_SUBMENU: case EXTRAS_SUBMENU: case FILES_SUBMENU:
      case RFID_SUBMENU: case NFC_SUBMENU:
        if (btnBPressed()) { nextSubmenuOption();     drawSubmenuOptions(); }
        if (btnCPressed()) { previousSubmenuOption(); drawSubmenuOptions(); }
        if (btnAPressed()) {
          int idx = getSubmenuOptionIndex();
          if (idx == 0) {
            switch(currentMenu) {
              case WIFI_SUBMENU:       currentMenu = WIFI_MENU;       drawWiFiMenu(); break;
              case BLUETOOTH_SUBMENU:  currentMenu = BLUETOOTH_MENU;  drawBluetoothMenu(); break;
              case IR_SUBMENU:         currentMenu = IR_MENU;         drawIRMenu(); break;
              case RF_SUBMENU:         currentMenu = RF_MENU;         drawRFMenu(); break;
              case NRF_SUBMENU:        currentMenu = NRF_MENU;        drawNRFMenu(); break;
              case RADIO_SUBMENU:      currentMenu = RADIO_MENU;      drawRadioMenu(); break;
              case GPS_SUBMENU:        currentMenu = GPS_MENU;        drawGPSMenu(); break;
              case RPI_SUBMENU:        currentMenu = RPI_MENU;        drawRPIMenu(); break;
              case BADUSB_SUBMENU:     currentMenu = BADUSB_MENU;     drawBadUSBMenu(); break;
              case SETTINGS_SUBMENU:   currentMenu = SETTINGS_MENU;   drawSettingsMenu(); break;
              case EXTRAS_SUBMENU:     currentMenu = EXTRAS_MENU;     drawExtrasMenu(); break;
              case FILES_SUBMENU:      currentMenu = FILES_MENU;      drawFilesMenu(); break;
              case RFID_SUBMENU:       currentMenu = RFID_MENU;       drawRfidMenu(); break;
              case NFC_SUBMENU:        currentMenu = NFC_MENU;        drawNfcMenu(); break;
              default: break;
            }
          } else {
            handleSubmenuAction(currentMenu, idx, tft,
                                inStopwatch, inOptionScreen, inBGone, inIRRead,
                                inWiFiScan, inPacketScan);
          }
        }
        return;
      default: break;
    }
  }

  static unsigned long last = 0;
  if (!inOptionScreen && !inStopwatch && !inIRRead && !inBGone &&
      !inWiFiScan && !inPacketScan && !sInBLEScan && !sInBLEGoogleAdv &&
      !sInBrightness && !sInIntegrated && !sInRpiInfo && !sInWebFiles) {
    if (now - last > 80) {
      if (btnBPressed()) {
        last = now;
        switch(currentMenu) {
          case WIFI_MENU:        currentMenu=NFC_MENU;         drawNfcMenu();        break;
          case BLUETOOTH_MENU:   currentMenu=WIFI_MENU;        drawWiFiMenu();       break;
          case IR_MENU:          currentMenu=BLUETOOTH_MENU;   drawBluetoothMenu();  break;
          case RF_MENU:          currentMenu=IR_MENU;          drawIRMenu();         break;
          case NRF_MENU:         currentMenu=RF_MENU;          drawRFMenu();         break;
          case RADIO_MENU:       currentMenu=NRF_MENU;         drawNRFMenu();        break;
          case GPS_MENU:         currentMenu=RADIO_MENU;       drawRadioMenu();      break;
          case RPI_MENU:         currentMenu=GPS_MENU;         drawGPSMenu();        break;
          case BADUSB_MENU:      currentMenu=RPI_MENU;         drawRPIMenu();        break;
          case SETTINGS_MENU:    currentMenu=BADUSB_MENU;      drawBadUSBMenu();     break;
          case EXTRAS_MENU:      currentMenu=SETTINGS_MENU;    drawSettingsMenu();   break;
          case FILES_MENU:       currentMenu=EXTRAS_MENU;      drawExtrasMenu();     break;
          case RFID_MENU:        currentMenu=FILES_MENU;       drawFilesMenu();      break;
          case NFC_MENU:         currentMenu=RFID_MENU;        drawRfidMenu();       break;
          default: break;
        }
      }
      if (btnCPressed()) {
        last = now;
        switch(currentMenu) {
          case WIFI_MENU:        currentMenu=BLUETOOTH_MENU;   drawBluetoothMenu();  break;
          case BLUETOOTH_MENU:   currentMenu=IR_MENU;          drawIRMenu();         break;
          case IR_MENU:          currentMenu=RF_MENU;          drawRFMenu();         break;
          case RF_MENU:          currentMenu=NRF_MENU;         drawNRFMenu();        break;
          case NRF_MENU:         currentMenu=RADIO_MENU;       drawRadioMenu();      break;
          case RADIO_MENU:       currentMenu=GPS_MENU;         drawGPSMenu();        break;
          case GPS_MENU:         currentMenu=RPI_MENU;         drawRPIMenu();        break;
          case RPI_MENU:         currentMenu=BADUSB_MENU;      drawBadUSBMenu();     break;
          case BADUSB_MENU:      currentMenu=SETTINGS_MENU;    drawSettingsMenu();   break;
          case SETTINGS_MENU:    currentMenu=EXTRAS_MENU;      drawExtrasMenu();     break;
          case EXTRAS_MENU:      currentMenu=FILES_MENU;       drawFilesMenu();      break;
          case FILES_MENU:       currentMenu=RFID_MENU;        drawRfidMenu();       break;
          case RFID_MENU:        currentMenu=NFC_MENU;         drawNfcMenu();        break;
          case NFC_MENU:         currentMenu=WIFI_MENU;        drawWiFiMenu();       break;
          default: break;
        }
      }
    }
  }

  if (!inOptionScreen && !inStopwatch && !inIRRead && !inBGone &&
      !inWiFiScan && !inPacketScan && !sInBLEScan && !sInBLEGoogleAdv &&
      !sInBrightness && !sInIntegrated && !sInRpiInfo && !sInWebFiles && btnAPressed()) {
    tft->fillScreen(TFT_BLACK);
    tft->setRotation(ROT_TOP);
#if defined(M5CARDPUTER)
    drawOptionsLayerBackground(*tft);
#endif
    switch (currentMenu) {
      case WIFI_MENU:        currentMenu = WIFI_SUBMENU;       setSubmenuType(SUBMENU_WIFI);       drawWiFisubmenu();       break;
      case BLUETOOTH_MENU:   currentMenu = BLUETOOTH_SUBMENU;  setSubmenuType(SUBMENU_BLUETOOTH);  drawBluetoothSubmenu();  break;
      case IR_MENU:          currentMenu = IR_SUBMENU;         setSubmenuType(SUBMENU_IR);         drawIrSubmenu();         break;
      case RF_MENU:          currentMenu = RF_SUBMENU;         setSubmenuType(SUBMENU_RF);         drawRfSubmenu();         break;
      case NRF_MENU:         currentMenu = NRF_SUBMENU;        setSubmenuType(SUBMENU_NRF);        drawNrfSubmenu();        break;
      case RADIO_MENU:       currentMenu = RADIO_SUBMENU;      setSubmenuType(SUBMENU_RADIO);      drawRadioSubmenu();      break;
      case GPS_MENU:         currentMenu = GPS_SUBMENU;        setSubmenuType(SUBMENU_GPS);        drawGpsSubmenu();        break;
      case RPI_MENU:         currentMenu = RPI_SUBMENU;        setSubmenuType(SUBMENU_RPI);        drawRpiSubmenu();        break;
      case BADUSB_MENU:      currentMenu = BADUSB_SUBMENU;     setSubmenuType(SUBMENU_BADUSB);     drawBadUsbSubmenu();     break;
      case SETTINGS_MENU:    currentMenu = SETTINGS_SUBMENU;   setSubmenuType(SUBMENU_SETTINGS);   drawSettingsSubmenu();   break;
      case EXTRAS_MENU:      currentMenu = EXTRAS_SUBMENU;     setSubmenuType(SUBMENU_EXTRAS);     drawExtrasSubmenu();     break;
      case FILES_MENU:       currentMenu = FILES_SUBMENU;      setSubmenuType(SUBMENU_FILES);      drawFilesSubmenu();      break;
      case RFID_MENU:        currentMenu = RFID_SUBMENU;       setSubmenuType(SUBMENU_RFID);       drawRfidSubmenu();       break;
      case NFC_MENU:         currentMenu = NFC_SUBMENU;        setSubmenuType(SUBMENU_NFC);        drawNfcSubmenu();        break;
      default: break;
    }
  }
}

extern "C" int passlock_button_read_blocking() {
  for (;;) {
    updateButtons();
    if (btnAPressed()) return 1;
    if (btnBPressed()) return 2;
    if (btnCPressed()) return 3;
    delay(5);
  }
}
