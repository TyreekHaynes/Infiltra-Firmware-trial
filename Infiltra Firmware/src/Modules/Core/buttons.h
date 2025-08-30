#pragma once
#include <TFT_eSPI.h>
#include "././UserInterface/menus/menu_enums.h"

void initButtons();
void updateButtons();
bool btnAPressed();
bool btnBPressed();
bool btnCPressed();
void finalizeButtons();

/**
 * Central input dispatcher.
 * - Routes A/B/C to the correct active module (Wi-Fi scan, packet scan, IR, BLE, etc.)
 * - Handles submenu navigation and top-level ring movement.
 *
 * Params:
 *   tft              Pointer to the global TFT instance
 *   inOptionScreen   Layered option panel (opened from submenu rows)
 *   inStopwatch      Stopwatch module active
 *   inBGone          IR B-Gone module active
 *   inIRRead         IR Read module active
 *   inWiFiScan       Wi-Fi scanner active
 *   inPacketScan     Packet scanner active
 *   currentMenu      Current top-level or submenu state (in/out param)
 */
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
