#ifndef UI_WEB_SERVER_H
#define UI_WEB_SERVER_H

#include <ESPAsyncWebServer.h>

void setupWebServer(AsyncWebServer* server, bool isSetupMode);
void handleSetupForm(AsyncWebServerRequest* request);

#endif
