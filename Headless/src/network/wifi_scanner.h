#ifndef NETWORK_WIFI_SCANNER_H
#define NETWORK_WIFI_SCANNER_H

#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJson.h>

struct WiFiNetworkInfo {
    String ssid;
    String bssid;
    int32_t rssi;
    uint8_t channel;
    String encryption;
    bool isHidden;
};

class WiFiScanner {
private:
    std::vector<WiFiNetworkInfo> networks;
    bool scanInProgress;
    unsigned long lastScanTime;
    
public:
    WiFiScanner();
    bool startScan();
    bool isScanComplete();
    std::vector<WiFiNetworkInfo> getNetworks();
    String getNetworksJson();
    void clearResults();
    int getNetworkCount();
    String getEncryptionType(wifi_auth_mode_t encryptionType);
    unsigned long getLastScanTime();
};

extern WiFiScanner wifiScanner;

#endif