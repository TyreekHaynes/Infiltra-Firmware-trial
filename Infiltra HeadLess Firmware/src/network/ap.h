#ifndef NETWORK_AP_H
#define NETWORK_AP_H

#include <Arduino.h>
#include <DNSServer.h>
#include <ESPAsyncWebServer.h>

void setupAP();
void loopAP();

DNSServer* getDnsServer();
AsyncWebServer* getWebServer();

#endif
