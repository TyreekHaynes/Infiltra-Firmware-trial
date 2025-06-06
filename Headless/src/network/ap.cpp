#include "ap.h"
#include "../core/config.h"
#include "../ui/web/server.h"
#include <WiFi.h>

#ifdef DEVICE_CARDPUTER
  #include <M5Cardputer.h>
#endif

DNSServer dnsServer;
AsyncWebServer webServer(WEBSERVER_PORT);

void setupAP() {
    setupMode = !loadSettings();
    WiFi.mode(WIFI_AP);
    
    if (deviceSettings.useStaticIP) {
        WiFi.softAPConfig(deviceSettings.ip, deviceSettings.gateway, deviceSettings.subnet);
    }
    
    if (deviceSettings.usePassword && strlen(deviceSettings.password) >= 8) {
        WiFi.softAP(deviceSettings.ssid, deviceSettings.password);
    } else {
        WiFi.softAP(deviceSettings.ssid);
    }

    IPAddress apIP = WiFi.softAPIP();   
    dnsServer.start(53, "*", apIP);
    setupWebServer(&webServer, setupMode);
    webServer.begin();
}

void loopAP() {
    dnsServer.processNextRequest();
}

DNSServer* getDnsServer() {
    return &dnsServer;
}

AsyncWebServer* getWebServer() {
    return &webServer;
}
