#pragma once
#include "././UserInterface/menus/menu_enums.h"

// Avoid including TFT headers here; we forward-declare to prevent clashes.
class TFT_eSPI;

void initButtons();
void updateButtons();
bool btnAPressed();
bool btnBPressed();
bool btnCPressed();
void finalizeButtons();

void handleAllButtonLogic(
  TFT_eSPI* tft,
  bool& inOptionScreen,
  bool& inStopwatch,
  bool& inBGone,
  bool& inIRRead,
  bool& inWiFiScan,
  bool& inPacketScan,
  MenuState& currentMenu
);
