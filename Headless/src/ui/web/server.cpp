#include "server.h"
#include "../../core/config.h"
#include "../../core/system.h"
#include "../../assets/html/landing_page.h"
#include "../../assets/html/setup_page.h"
#include "../../assets/css/style.h"
#include "../../assets/css/setup_style.h"
#include <ESP.h>

void setupWebServer(AsyncWebServer* server, bool isSetupMode) {
    if (isSetupMode) {
        server->on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
            request->send(200, "text/html", SETUP_PAGE_HTML);
        });

        server->on("/saveconfig", HTTP_POST, handleSetupForm);
    } else {
        server->on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
            request->send(200, "text/html", LANDING_PAGE_HTML);
        });
    }

    server->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/css", STYLE_CSS);
    });
    
    server->on("/setup_style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/css", SETUP_STYLE_CSS);
    });
    
    server->on("/deviceinfo", HTTP_GET, [](AsyncWebServerRequest *request) {
        String deviceType;
        
        #ifdef M5STICK_1
            deviceType = isM5StickCPlus1() ? "M5StickC Plus 1.1" : "M5StickC Plus 2.0";
        #elif defined(CARDPUTER)
            deviceType = "M5Stack Cardputer";
        #elif defined(LILYGO_T_EMBED)
            #ifdef LILYGO_T_EMBED_CC1101
                deviceType = "LilyGO T-Embed CC1101";
            #else
                deviceType = "LilyGO T-Embed";
            #endif
        #else
            deviceType = "Unknown Device";
        #endif

        String info = "Device Type: " + deviceType;
        request->send(200, "text/plain", info);
    });

    server->onNotFound([](AsyncWebServerRequest *request) {
        request->redirect("/");
    });
}  

void handleSetupForm(AsyncWebServerRequest* request) {
    if (request->hasParam("ssid", true)) {
        strncpy(deviceSettings.ssid, request->getParam("ssid", true)->value().c_str(), sizeof(deviceSettings.ssid));
    }
    
    deviceSettings.usePassword = request->hasParam("usePassword", true);
    
    if (deviceSettings.usePassword && request->hasParam("password", true)) {
        strncpy(deviceSettings.password, request->getParam("password", true)->value().c_str(), sizeof(deviceSettings.password));
    } else {
        deviceSettings.password[0] = '\0';
    }
    
    deviceSettings.useStaticIP = request->hasParam("useStaticIP", true);
    
    if (deviceSettings.useStaticIP && request->hasParam("ipPreset", true)) {
        String ipString = request->getParam("ipPreset", true)->value();
        IPAddress selectedIP;
        
        if (selectedIP.fromString(ipString)) {
            deviceSettings.ip = selectedIP;
            deviceSettings.gateway = deviceSettings.ip;
            deviceSettings.subnet = IPAddress(255, 255, 255, 0);
        } else {
            deviceSettings.ip = IPAddress(192, 168, 4, 1);
            deviceSettings.gateway = deviceSettings.ip;
            deviceSettings.subnet = IPAddress(255, 255, 255, 0);
        }
    }

    deviceSettings.disableBeep = request->hasParam("disableBeep", true);
    deviceSettings.initialized = true;

    if (saveSettings()) {
        request->send(200, "text/html", 
            "<html><head><meta http-equiv='refresh' content='5;URL=/'>"
            "<link rel='stylesheet' href='style.css'>"
            "<link rel='stylesheet' href='setup_style.css'></head>"
            "<body style='font-family: Arial, sans-serif; text-align: center; padding-top: 50px;'>"
            "<h1>Configuration Saved</h1>"
            "<p>Your settings have been saved. The device will restart in 5 seconds.</p>"
            "<p>Connect to the new network: <strong>" + String(deviceSettings.ssid) + "</strong></p>"
            "</body></html>");
        
        delay(2000);
        ESP.restart();
    } else {
        request->send(500, "text/html", 
            "<html><head>"
            "<link rel='stylesheet' href='style.css'>"
            "<link rel='stylesheet' href='setup_style.css'></head>"
            "<body style='font-family: Arial, sans-serif; text-align: center; padding-top: 50px;'>"
            "<h1>Error</h1>"
            "<p>Failed to save configuration. Please try again.</p>"
            "<a href='/'>Go Back</a>"
            "</body></html>");
    }
}
