#ifndef SUBMENU_OPTIONS_H
#define SUBMENU_OPTIONS_H

#include <TFT_eSPI.h>
#include <Arduino.h>

enum SubmenuType {
    SUBMENU_WIFI,
    SUBMENU_BLUETOOTH,
    SUBMENU_IR,
    SUBMENU_RF,
    SUBMENU_NRF,
    SUBMENU_RADIO,
    SUBMENU_GPS,
    SUBMENU_RPI,
    SUBMENU_BADUSB,
    SUBMENU_SETTINGS,
    SUBMENU_EXTRAS,
    SUBMENU_FILES,
    SUBMENU_RFID,
    SUBMENU_NFC
};

void initSubmenuOptions(TFT_eSPI* display);
void setSubmenuType(SubmenuType type);
void drawSubmenuOptions();
void nextSubmenuOption();
void previousSubmenuOption();
int    getSubmenuOptionIndex();
String getSubmenuOptionText();

#endif 
