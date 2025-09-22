#pragma once
#include <Arduino.h>

void keyboard();
bool BtKeyboard_isConnected();
void BtKeyboard_pushChar(char c);
void BtKeyboard_sendString(const String &s);
void BtKeyboard_end();
