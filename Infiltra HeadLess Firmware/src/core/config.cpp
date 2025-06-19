#include "config.h"
#include "../utils/filesystem.h"
#include "WiFi.h"

DeviceSettings deviceSettings;
bool setupMode = false;

void loadDefaultSettings() {
    strncpy(deviceSettings.ssid, "Infiltra_AP", sizeof(deviceSettings.ssid));
    deviceSettings.password[0] = '\0';
    deviceSettings.ip = IPAddress(192, 168, 4, 1);
    deviceSettings.gateway = IPAddress(192, 168, 4, 1);
    deviceSettings.subnet = IPAddress(255, 255, 255, 0);
    deviceSettings.usePassword = false;
    deviceSettings.useStaticIP = false;
    deviceSettings.initialized = false;
    deviceSettings.disableBeep = false;
}

bool loadSettings() {
    if (!initFileSystem()) {
        loadDefaultSettings();
        return false;
    }

    if (!fileExists("/settings.json")) {
        loadDefaultSettings();
        return false;
    }
    
    String jsonData = readFile("/settings.json");
    if (jsonData.length() == 0) {
        loadDefaultSettings();
        return false;
    }

    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, jsonData);
    
    if (error) {
        loadDefaultSettings();
        return false;
    }

    strncpy(deviceSettings.ssid, doc["ssid"] | "Infiltra_AP", sizeof(deviceSettings.ssid));
    strncpy(deviceSettings.password, doc["password"] | "", sizeof(deviceSettings.password));
    String ipStr = doc["ip"] | "192.168.4.1";
    String gatewayStr = doc["gateway"] | "192.168.4.1";
    String subnetStr = doc["subnet"] | "255.255.255.0";
    deviceSettings.ip.fromString(ipStr);
    deviceSettings.gateway.fromString(gatewayStr);
    deviceSettings.subnet.fromString(subnetStr);
    deviceSettings.usePassword = doc["usePassword"] | false;
    deviceSettings.useStaticIP = doc["useStaticIP"] | false;
    deviceSettings.initialized = doc["initialized"] | false;
    deviceSettings.disableBeep = doc["disableBeep"] | false;
    
    return deviceSettings.initialized;
}

bool saveSettings() {
    if (!initFileSystem()) {
        return false;
    }

    JsonDocument doc;
    doc["ssid"] = deviceSettings.ssid;
    doc["password"] = deviceSettings.password;
    doc["ip"] = deviceSettings.ip.toString();
    doc["gateway"] = deviceSettings.gateway.toString();
    doc["subnet"] = deviceSettings.subnet.toString();
    doc["usePassword"] = deviceSettings.usePassword;
    doc["useStaticIP"] = deviceSettings.useStaticIP;
    doc["initialized"] = deviceSettings.initialized;
    doc["disableBeep"] = deviceSettings.disableBeep;
    
    String jsonData;
    serializeJson(doc, jsonData);
    
    return writeFile("/settings.json", jsonData);
}

bool isWiFiHardwareAvailable() {
    if (WiFi.getMode() == WIFI_MODE_NULL) {
        WiFi.mode(WIFI_STA);
        delay(10);
        if (WiFi.getMode() != WIFI_STA) {
            return false;
        }
    }
    
    return true;
}
