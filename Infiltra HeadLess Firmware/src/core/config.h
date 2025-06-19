#ifndef CORE_CONFIG_H
#define CORE_CONFIG_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <IPAddress.h>

const char* const DEFAULT_AP_NAME = "Infiltra_AP";
const int WEBSERVER_PORT = 80;

struct DeviceSettings {
    char ssid[32];
    char password[64];
    IPAddress ip;
    IPAddress gateway;
    IPAddress subnet;
    bool usePassword;
    bool useStaticIP;
    bool initialized;
    bool disableBeep;
};

extern DeviceSettings deviceSettings;
extern bool setupMode;
void loadDefaultSettings();
bool loadSettings();
bool saveSettings();

#endif