#include <M5StickCPlus2.h>
#include <SPIFFS.h>
#include <IRremote.h>
#include <WiFi.h>
#include <esp_wifi.h>
#include <algorithm>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>

using std::min;

struct WiFiScanResult {
    String ssid;
    int32_t rssi;
    uint8_t channel;
    wifi_auth_mode_t encType;
    uint8_t bssid[6];
};

struct BLEDeviceInfo {
    String name;
    String address;
    int rssi;
    String type;
    bool isConnectable;
};

struct SkimmerDevice {
    String deviceType;
    String frequency;
    int signalStrength;
    String protocol;
    String dataRate;
    bool isActive;
};

struct IRCodes {
    unsigned long powerOn[5];
    unsigned long powerOff[5];
};

struct UITheme {
    uint16_t primary;
    uint16_t secondary;
    uint16_t accent;
    uint16_t background;
    const char* name;
};

const int DEFAULT_IR_SEND_PIN = 19;
const int DEFAULT_IR_RECEIVE_PIN = 33;
const int DEFAULT_RF_RECEIVER_PIN = 33;
const int DEFAULT_RF_TRANSMIT_PIN = 32;
const int IR_RECEIVE_PIN = DEFAULT_IR_RECEIVE_PIN;

int ir_send_pin = DEFAULT_IR_SEND_PIN;
int ir_receive_pin = DEFAULT_IR_RECEIVE_PIN;
int rf_receiver_pin = DEFAULT_RF_RECEIVER_PIN;
int rf_transmit_pin = DEFAULT_RF_TRANSMIT_PIN;

bool inCustomFqOverlay = false;
bool inFixedFqOverlay = false;
int currentCustomFqOption = 0;
float selectedFrequency = 433.92;
int currentRfModule = 0;
const int numFixedFrequencies = 10;
const float fixedFrequencies[10] = {
    315.0, 433.92, 868.0, 915.0, 2400.0, 
    434.0, 435.0, 866.0, 902.0, 928.0
};
int currentFixedFqOption = 0;
float current_rf_frequency = 433.92;
const float RF_FREQUENCY = 433.92;
const float JAM_FREQUENCY = 433.92;

bool inJammerModeOverlay = false;
int currentJammerMode = 0;
bool jammerTargetMode = false;
float targetJamFrequency = 433.92;
const int numTargetFrequencies = 5;
const float targetFrequencies[numTargetFrequencies] = {
    433.42, 433.67, 433.92, 434.17, 434.42
};
int currentTargetFreqIndex = 2;

bool inIrModsOverlay = false;
bool inRfModsOverlay = false;
int currentIrModOption = 0;
int currentRfModOption = 0;

const int MAX_FILE_SIZE = 5000;
const char* SIGNALXNETWORK_DIR = "/SXN";
const int itemSpacing = 25;

const int PACKET_HISTORY_SIZE = 100;
const int GRAPH_WIDTH = 120;
const int GRAPH_HEIGHT = 100;
int signalStrength[GRAPH_WIDTH];
int packetHistory[PACKET_HISTORY_SIZE];
int historyIndex = 0;
unsigned long rfSignalCount = 0;
unsigned long totalPackets = 0;
unsigned long packetsPerSecond = 0;
unsigned long lastPacketCount = 0;
unsigned long lastCounterUpdate = 0;
int currentWiFiChannel = 1;
bool rfJammerFirstRun = true;
bool rfVisualizerFirstRun = true;

bool inSubmenu = false;
bool scanning = false;
bool inFileMenu = true;
bool inIrRemoteMenu = false;
bool inBrandMenu = false;
bool inActionOverlay = false;
bool inRfVisualizer = false;
bool inRfJammer = false;
bool inWiFiScan = false;
bool inPacketMonitor = false;
bool inBleScanner = false;
bool inCardSkimmer = false;
bool inColorSelection = false;
bool inIrReplay = false;
bool codeReceived = false;

unsigned long capturedIrCode = 0;

int currentMenuItem = 0;
int currentSubMenuItem = 0;
int currentBrandMenuItem = 0;
int currentDeviceType = 0;
int bleDeviceCount = 0;
int currentBleDevice = 0;
int skimmerCount = 0;
int currentSkimmer = 0;

BLEDeviceInfo* bleDevices = nullptr;
SkimmerDevice* skimmerDevices = nullptr;

UITheme currentTheme = {WHITE, RED, 0x4208, BLACK, "Original"};
const UITheme themes[] = {
    {WHITE, RED, 0x4208, BLACK, "Original"},
    {GREEN, YELLOW, 0x0618, BLACK, "Matrix"},
    {CYAN, MAGENTA, 0x4B0D, BLACK, "Cyberpunk"},
    {YELLOW, BLUE, 0x6B0C, BLACK, "Electric"},
    {0xFD20, 0xFB2F, 0xF800, BLACK, "Sunset"}
};

void drawHeader();
void drawNavigationDots();
void displayMenuItem();
void displaySubMenu();
void displayActionOverlay();
void displayNetwork(int index, int total, WiFiScanResult* networks);
void displayBleDevice(int index, int total, BLEDeviceInfo* devices);
void displaySkimmerInfo(int index);
void handlePowerButton();
void handleMainMenu();
void handleSubMenu();
void handleSubMenuSelection();
void handleBrandMenu();
void handleActionOverlay();
void handleRfJammer();
void handleRfVisualizer();
void handleWiFiScan();
void handlePacketMonitor();
void handleBleScanner();
void handleCardSkimmer();
void handleColorSelection();
void handleIrReplay();
void drawPacketMonitorScreen();
void promiscuousCallback(void* buf, wifi_promiscuous_pkt_type_t type);
const char* getEncryptionType(wifi_auth_mode_t encType);
int getMaxSubMenuItems();
void spamIRCodes(int deviceType, int brandIndex);
void handleDeauthAction(bool target);
void performDeauth(WiFiScanResult* network, int count);
void displayCustomFqOverlay();
void displayIrModsOverlay();
void drawIrModsOverlay();
void handleIrModsOverlay();
void displayRfModsOverlay();
void drawRfModsOverlay();
void handleRfModsOverlay();
void displayFixedFqOverlay();
void drawFixedFqOverlay();
void handleFixedFqOverlay();
void drawCustomFqOverlay();
void handleCustomFqOverlay();
void displayJammerModeOverlay();
void displayTargetFrequencyOverlay();

const char* menuItems[] = {
    "Bluetooth", "WiFi", "RFID", "RF", "IR", "Files", "Config", "Settings"
};

const char* bluetoothMenu[] = {
    "Ios Spam", "Android Spam", "Google Spam", "Windows Spam", "Samsung Spam", "Ble Controller", "BLE Scanner", "Card Skim"
};

const char* wifiMenu[] = {
    "Scan Networks", "Evil Portal", "Raw Sniffer", "Packet Sniffer", "Deauth WiFi"
};

const char* rfidMenu[] = {
    "Copy RFID", "Scan Tags", "Write Tags", "Erase Tag", "Load File"
};

const char* rfMenu[] = {
    "RF Vizulizer", "Jammer", "Custom FQ", "Custom SubGhz"
};

const char* filesMenu[] = {
    "Integrated", "Web Send Files"
};

const char* irMenu[] = {
    "IR Remote", "IR Replay", "Custom IR"
};

const char* irRemoteMenu[] = {
    "TV's", "Projectors", "LedLights", "Whiteboards", "Touch Displays"
};

const char* configMenu[] = {
    "IR Mods", "Rf Mods", "RFID Mods"
};

const char* settingsMenu[] = {
    "UI Color", "Time", "Creds"
};

const char* tvBrands[] = {
    "Samsung", "LG", "Sony", "Hisense", "Philips", "Panasonic"
};

const char* projectorBrands[] = {
    "Epson", "BenQ", "ViewSonic", "Optoma", "Christie"
};

const char* ledLightBrands[] = {
    "Philips Hue", "LIFX", "Nanoleaf", "Govee", "TechLight"
};

const char* whiteboardBrands[] = {
    "Smart", "Promethean", "Clevertouch", "Boxlight", "Newline"
};

const char* touchDisplayBrands[] = {
    "ViewSonic", "Dell", "NEC", "Sharp", "LG"
};

const char* brandActions[] = {
    "Spam All"
};

const char* deauthActions[] = {
    "Spam All",
    "Target"
};

const char* replayActions[] = {
    "Replay Code"
};

const char* irModOptions[] = {
    "Default", "M5 ir mod", "G26"
};

const char* rfModOptions[] = {
    "M5 Mod T/R", "G26", "CC1101"
};

const char* customFqOptions[] = {
    "Default", "433.05-434.790", "Fixed FQ"

};

const int numIrModOptions = sizeof(irModOptions) / sizeof(irModOptions[0]);
const int numMenuItems = sizeof(menuItems) / sizeof(menuItems[0]);
const int numBluetoothItems = sizeof(bluetoothMenu) / sizeof(bluetoothMenu[0]);
const int numWifiItems = sizeof(wifiMenu) / sizeof(wifiMenu[0]);
const int numRfidItems = sizeof(rfidMenu) / sizeof(rfidMenu[0]);
const int numRfItems = sizeof(rfMenu) / sizeof(rfMenu[0]);
const int numFilesItems = sizeof(filesMenu) / sizeof(filesMenu[0]);
const int numIrItems = sizeof(irMenu) / sizeof(irMenu[0]);
const int numIrRemoteItems = sizeof(irRemoteMenu) / sizeof(irRemoteMenu[0]);
const int numConfigItems = sizeof(configMenu) / sizeof(configMenu[0]);
const int numSettingsItems = sizeof(settingsMenu) / sizeof(settingsMenu[0]);
const int numTvBrands = sizeof(tvBrands) / sizeof(tvBrands[0]);
const int numProjectorBrands = sizeof(projectorBrands) / sizeof(projectorBrands[0]);
const int numLedLightBrands = sizeof(ledLightBrands) / sizeof(ledLightBrands[0]);
const int numWhiteboardBrands = sizeof(whiteboardBrands) / sizeof(whiteboardBrands[0]);
const int numTouchDisplayBrands = sizeof(touchDisplayBrands) / sizeof(touchDisplayBrands[0]);
const int numRfModOptions = sizeof(rfModOptions) / sizeof(rfModOptions[0]);
const int numCustomFqOptions = sizeof(customFqOptions) / sizeof(customFqOptions[0]);

const IRCodes TV_CODES[] = {
    // Samsung
    {{0xE0E040BF, 0xE0E0E01F, 0xE0E0D02F, 0xE0E019E6, 0xE0E0F00F},
     {0xE0E019E6, 0xE0E0D827, 0xE0E0C837, 0xE0E09966, 0xE0E0B04F}},
    // LG
    {{0x20DF10EF, 0x20DF23DC, 0x20DFA956, 0x20DF8877, 0x20DF0CF3},
     {0x20DF23DC, 0x20DFB44B, 0x20DF708F, 0x20DF916E, 0x20DF5AA5}},
    // Sony
    {{0xA90, 0xA50, 0xA70, 0xA30, 0xA10},
     {0xA90, 0xA50, 0xA70, 0xA30, 0xA10}},
    // Hisense
    {{0x55AA50AF, 0x55AAF00F, 0x55AA926D, 0x55AA58A7, 0x55AA7887},
     {0x55AAD02F, 0x55AA30CF, 0x55AA28D7, 0x55AAB847, 0x55AA6897}},
    // Philips
    {{0x0C32, 0x0C34, 0x0C36, 0x0C38, 0x0C40},
     {0x0C32, 0x0C34, 0x0C36, 0x0C38, 0x0C40}},
    // Panasonic
    {{0x100BCBD, 0x100ACAD, 0x1009C9D, 0x1008C8D, 0x1007C7D},
     {0x100BCBD, 0x100ACAD, 0x1009C9D, 0x1008C8D, 0x1007C7D}}
};

const IRCodes PROJECTOR_CODES[] = {
    // Epson
    {{0x4CB340BF, 0x4CB341BE, 0x4CB342BD, 0x4CB343BC, 0x4CB344BB},
     {0x4CB3748B, 0x4CB3758A, 0x4CB37689, 0x4CB37788, 0x4CB37887}},
    // BenQ
    {{0xC4DA0001, 0xC4DA0002, 0xC4DA0003, 0xC4DA0004, 0xC4DA0005},
     {0xC4DA1001, 0xC4DA1002, 0xC4DA1003, 0xC4DA1004, 0xC4DA1005}},
    // ViewSonic
    {{0x80D01001, 0x80D01002, 0x80D01003, 0x80D01004, 0x80D01005},
     {0x80D02001, 0x80D02002, 0x80D02003, 0x80D02004, 0x80D02005}},
    // Optoma
    {{0xC1AA0001, 0xC1AA0002, 0xC1AA0003, 0xC1AA0004, 0xC1AA0005},
     {0xC1AA1001, 0xC1AA1002, 0xC1AA1003, 0xC1AA1004, 0xC1AA1005}},
    // Christie
    {{0x1CE30001, 0x1CE30002, 0x1CE30003, 0x1CE30004, 0x1CE30005},
     {0x1CE31001, 0x1CE31002, 0x1CE31003, 0x1CE31004, 0x1CE31005}}
};

const IRCodes LED_CODES[] = {
    // Philips Hue
    {{0x7887A001, 0x7887A002, 0x7887A003, 0x7887A004, 0x7887A005},
     {0x7887B001, 0x7887B002, 0x7887B003, 0x7887B004, 0x7887B005}},
    // LIFX
    {{0x5AA5C001, 0x5AA5C002, 0x5AA5C003, 0x5AA5C004, 0x5AA5C005},
     {0x5AA5D001, 0x5AA5D002, 0x5AA5D003, 0x5AA5D004, 0x5AA5D005}},
    // Nanoleaf
    {{0x9966E001, 0x9966E002, 0x9966E003, 0x9966E004, 0x9966E005},
     {0x9966F001, 0x9966F002, 0x9966F003, 0x9966F004, 0x9966F005}},
    // Govee
    {{0x4BB61001, 0x4BB61002, 0x4BB61003, 0x4BB61004, 0x4BB61005},
     {0x4BB62001, 0x4BB62002, 0x4BB62003, 0x4BB62004, 0x4BB62005}},
    // TechLight
    {{0x3DD31001, 0x3DD31002, 0x3DD31003, 0x3DD31004, 0x3DD31005},
     {0x3DD32001, 0x3DD32002, 0x3DD32003, 0x3DD32004, 0x3DD32005}}
};

const IRCodes WHITEBOARD_CODES[] = {
    // Smart
    {{0x4AB51001, 0x4AB51002, 0x4AB51003, 0x4AB51004, 0x4AB51005},
     {0x4AB52001, 0x4AB52002, 0x4AB52003, 0x4AB52004, 0x4AB52005}},
    // Promethean
    {{0x5AA51001, 0x5AA51002, 0x5AA51003, 0x5AA51004, 0x5AA51005},
     {0x5AA52001, 0x5AA52002, 0x5AA52003, 0x5AA52004, 0x5AA52005}},
    // Clevertouch
    {{0x6CC51001, 0x6CC51002, 0x6CC51003, 0x6CC51004, 0x6CC51005},
     {0x6CC52001, 0x6CC52002, 0x6CC52003, 0x6CC52004, 0x6CC52005}},
    // Boxlight
    {{0x7EE51001, 0x7EE51002, 0x7EE51003, 0x7EE51004, 0x7EE51005},
     {0x7EE52001, 0x7EE52002, 0x7EE52003, 0x7EE52004, 0x7EE52005}},
    // Newline
    {{0x8001001, 0x8001002, 0x8001003, 0x8001004, 0x8001005},
     {0x8002001, 0x8002002, 0x8002003, 0x8002004, 0x8002005}}
};

const IRCodes TOUCH_DISPLAY_CODES[] = {
    // ViewSonic
    {{0x9AB51001, 0x9AB51002, 0x9AB51003, 0x9AB51004, 0x9AB51005},
     {0x9AB52001, 0x9AB52002, 0x9AB52003, 0x9AB52004, 0x9AB52005}},
    // Dell
    {{0xAAC51001, 0xAAC51002, 0xAAC51003, 0xAAC51004, 0xAAC51005},
     {0xAAC52001, 0xAAC52002, 0xAAC52003, 0xAAC52004, 0xAAC52005}},
    // NEC
    {{0xBBD51001, 0xBBD51002, 0xBBD51003, 0xBBD51004, 0xBBD51005},
     {0xBBD52001, 0xBBD52002, 0xBBD52003, 0xBBD52004, 0xBBD52005}},
    // Sharp
    {{0xCCE51001, 0xCCE51002, 0xCCE51003, 0xCCE51004, 0xCCE51005},
     {0xCCE52001, 0xCCE52002, 0xCCE52003, 0xCCE52004, 0xCCE52005}},
    // LG
    {{0xDDF51001, 0xDDF51002, 0xDDF51003, 0xDDF51004, 0xDDF51005},
     {0xDDF52001, 0xDDF52002, 0xDDF52003, 0xDDF52004, 0xDDF52005}}
};

void setup() {
    M5.begin();
    IrSender.begin(ir_send_pin);
    
    if(!SPIFFS.begin(true)) {
        M5.Lcd.println("SPIFFS Mount Failed");
        return;
    }
    
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    esp_wifi_set_promiscuous(true);
    esp_wifi_set_promiscuous_rx_cb(&promiscuousCallback);
    
    M5.Lcd.setRotation(3);
    M5.Lcd.setTextSize(3);
    M5.Lcd.setTextColor(WHITE);
    displayMenuItem();
}

void loop() {
    M5.update();
    
    static bool firstRun = true;
    
    if (M5.BtnPWR.wasPressed()) {
        if (inJammerModeOverlay) {
            inJammerModeOverlay = false;
            firstRun = true;
        } else if (inRfJammer) {
            inRfJammer = false;
            inSubmenu = true;
            firstRun = true;
            displaySubMenu();
        } else if (inRfVisualizer) {
            inRfVisualizer = false;
            inSubmenu = true;
            rfVisualizerFirstRun = true;
            displaySubMenu();
        } else if (inWiFiScan) {
            inWiFiScan = false;
            inSubmenu = true;
            displaySubMenu();
        } else if (inPacketMonitor) {
            inPacketMonitor = false;
            WiFi.mode(WIFI_STA);
            inSubmenu = true;
            displaySubMenu();
        } else if (inBleScanner) {
            inBleScanner = false;
            inSubmenu = false;
            displayMenuItem();
        } else if (inCardSkimmer) {
            inCardSkimmer = false;
            inSubmenu = false;
            displayMenuItem();
        } else if (inColorSelection) {
            inColorSelection = false;
            inSubmenu = true;
            displaySubMenu();
        } else if (inIrReplay) {
            inIrReplay = false;
            inSubmenu = true;
            displaySubMenu();
        } else if (inIrModsOverlay) {
            inIrModsOverlay = false;
            displaySubMenu();
        } else if (inRfModsOverlay) {
            inRfModsOverlay = false;
            displaySubMenu();
        } else if (inCustomFqOverlay) {
            inCustomFqOverlay = false;
            displaySubMenu();
        } else if (inFixedFqOverlay) {
            inFixedFqOverlay = false;
            inCustomFqOverlay = true;
            drawCustomFqOverlay();
        } else {
            handlePowerButton();
        }
    }

    if (inJammerModeOverlay) {
        displayJammerModeOverlay();
    } else if (inRfJammer) {
        handleRfJammer();
    } else if (inRfVisualizer) {
        handleRfVisualizer();
    } else if (inWiFiScan) {
        handleWiFiScan();
    } else if (inPacketMonitor) {
        handlePacketMonitor();
    } else if (inBleScanner) {
        handleBleScanner();
    } else if (inCardSkimmer) {
        handleCardSkimmer();
    } else if (inColorSelection) {
        handleColorSelection();
    } else if (inActionOverlay) {
        handleActionOverlay();
    } else if (inBrandMenu) {
        handleBrandMenu();
    } else if (inIrReplay) {
        handleIrReplay();
    } else if (inIrModsOverlay) {
        handleIrModsOverlay();
    } else if (inRfModsOverlay) {
        handleRfModsOverlay();
    } else if (inCustomFqOverlay) {
        handleCustomFqOverlay();
    } else if (inFixedFqOverlay) {
        handleFixedFqOverlay();
    } else if (!inSubmenu) {
        handleMainMenu();
    } else {
        handleSubMenu();
    }
}
void handlePowerButton() {
    if (inActionOverlay) {
        inActionOverlay = false;
        displaySubMenu();
    } else if (inBrandMenu) {
        currentSubMenuItem = (currentSubMenuItem - 1 + getMaxSubMenuItems()) % getMaxSubMenuItems();
        displaySubMenu();
    } else if (inSubmenu) {
        currentSubMenuItem = (currentSubMenuItem - 1 + getMaxSubMenuItems() + 1) % (getMaxSubMenuItems() + 1);
        displaySubMenu();
    } else {
        currentMenuItem = (currentMenuItem - 1 + numMenuItems) % numMenuItems;
        displayMenuItem();
    }
}

void handleRfVisualizer() {
    static int lastRfValue = 0;
    static unsigned long lastSignalCount = 0;
    
    int rfValue = analogRead(rf_receiver_pin);
    float frequency;

    if (currentCustomFqOption == 1) { 
        frequency = 433.05 + (rfValue / 4095.0) * 1.74;
    } else {
        frequency = selectedFrequency + (rfValue / 4095.0) * 0.5;
    }
    
    if (rfVisualizerFirstRun) {
        M5.Lcd.fillRect(0, 21, M5.Lcd.width(), M5.Lcd.height()-21, BLACK);
        drawHeader();
        
        M5.Lcd.drawFastVLine(M5.Lcd.width()/2 - 1, 21, M5.Lcd.height()-21, 0x4208);
        M5.Lcd.drawFastVLine(M5.Lcd.width()/2, 21, M5.Lcd.height()-21, WHITE);
        M5.Lcd.drawFastVLine(M5.Lcd.width()/2 + 1, 21, M5.Lcd.height()-21, 0x4208);
        
        int rightMargin = M5.Lcd.width()/2 + 8;
        
        M5.Lcd.fillRoundRect(rightMargin, 25, 80, 25, 4, 0x4208);
        M5.Lcd.fillRoundRect(rightMargin, 55, 80, 35, 4, 0x2104);
        M5.Lcd.fillRoundRect(rightMargin, 95, 80, 45, 4, 0x4208);
        
        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(GREEN);
        M5.Lcd.setCursor(rightMargin + 5, 60);
        M5.Lcd.print("STRENGTH");
        
        M5.Lcd.setTextColor(YELLOW);
        M5.Lcd.setCursor(rightMargin + 5, 100);
        M5.Lcd.print("SIGNALS");
        
        rfVisualizerFirstRun = false;
    }
    
    if (abs(rfValue - lastRfValue) > 50 || rfSignalCount != lastSignalCount) {
        int rightMargin = M5.Lcd.width()/2 + 8;
        
        M5.Lcd.fillRect(rightMargin + 5, 28, 70, 15, 0x4208);
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(CYAN);
        M5.Lcd.setCursor(rightMargin + 5, 28);
        M5.Lcd.printf("%.3f", frequency);
        M5.Lcd.setTextSize(1);
        M5.Lcd.setCursor(rightMargin + 5, 43);
        M5.Lcd.print("MHz");
        
        M5.Lcd.fillRect(rightMargin + 5, 72, 70, 12, BLACK);
        int barWidth = map(rfValue, 0, 4095, 0, 70);
        M5.Lcd.fillRect(rightMargin + 5, 72, barWidth, 12, GREEN);
        M5.Lcd.drawRect(rightMargin + 5, 72, 70, 12, 0x4208);
        
        M5.Lcd.fillRect(rightMargin + 5, 115, 70, 20, 0x4208);
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.setCursor(rightMargin + 5, 115);
        M5.Lcd.print(rfSignalCount);
        
        for(int i = 0; i < GRAPH_WIDTH-1; i++) {
            signalStrength[i] = signalStrength[i+1];
        }
        signalStrength[GRAPH_WIDTH-1] = map(rfValue, 0, 4095, 0, GRAPH_HEIGHT);
        
        M5.Lcd.fillRect(0, 21, M5.Lcd.width()/2 - 2, M5.Lcd.height()-21, BLACK);
        for(int i = 0; i < GRAPH_WIDTH-1; i++) {
            uint16_t intensity = map(signalStrength[i], 0, GRAPH_HEIGHT, 0, 255);
            uint16_t color = M5.Lcd.color565(0, intensity, intensity);
            M5.Lcd.drawLine(i, M5.Lcd.height()-signalStrength[i], 
                            i, M5.Lcd.height(), color);
            if(signalStrength[i] > 10) {
                M5.Lcd.drawPixel(i, M5.Lcd.height()-signalStrength[i]-1, 0x4208);
            }
        }
        
        lastRfValue = rfValue;
        lastSignalCount = rfSignalCount;
    }
    
    if(rfValue > 2048) {
        rfSignalCount++;
    }

    static unsigned long lastModeUpdate = 0;
    if (millis() - lastModeUpdate > 5000) {
        int rightMargin = M5.Lcd.width()/2 + 8;
        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(YELLOW);

        String modName;
        switch(currentRfModule) {
            case 1: modName = "M5 MOD"; break;
            case 2: modName = "G26"; break;
            case 3: modName = "CC1101"; break;
            default: modName = "DEFAULT"; break;
        }

        String freqMode;
        if (currentCustomFqOption == 1) {
            freqMode = "RANGE";
        } else if (currentCustomFqOption == 2) {
            freqMode = "FIXED";
        } else {
            freqMode = "DEFAULT";
        }
        
        M5.Lcd.fillRect(5, 25, 100, 15, BLACK);
        M5.Lcd.setCursor(5, 25);
        M5.Lcd.print("MOD: " + modName);
        
        M5.Lcd.fillRect(5, 40, 100, 15, BLACK);
        M5.Lcd.setCursor(5, 40);
        M5.Lcd.print("FQ: " + freqMode);
        
        lastModeUpdate = millis();
    }
    
    delay(50);
}

void handleRfJammer() {
    static bool firstRun = true;
    static unsigned long jamCount = 0;
    static bool runnningJammer = false;
    static unsigned long lastUpdate = 0;
    
    if (firstRun) {
        M5.Lcd.fillScreen(BLACK);
        drawHeader();
        
        M5.Lcd.drawFastVLine(M5.Lcd.width()/2 - 1, 21, M5.Lcd.height()-21, 0x4208);
        M5.Lcd.drawFastVLine(M5.Lcd.width()/2, 21, M5.Lcd.height()-21, WHITE);
        M5.Lcd.drawFastVLine(M5.Lcd.width()/2 + 1, 21, M5.Lcd.height()-21, 0x4208);
        
        int rightMargin = M5.Lcd.width()/2 + 8;
        
        M5.Lcd.fillRoundRect(rightMargin, 25, 80, 25, 4, 0x4208);
        M5.Lcd.fillRoundRect(rightMargin, 55, 80, 35, 4, 0x2104);
        M5.Lcd.fillRoundRect(rightMargin, 95, 80, 45, 4, 0x4208);
        
        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.setCursor(5, 30);
        M5.Lcd.print("Range: ~10m");
        M5.Lcd.setCursor(5, 50);
        M5.Lcd.print("Power: 100mW");
        M5.Lcd.setCursor(5, 70);
        M5.Lcd.print("Band: ISM");

        M5.Lcd.setCursor(5, 90);
        M5.Lcd.print("Mode: ");
        M5.Lcd.setTextColor(GREEN);
        M5.Lcd.print(jammerTargetMode ? "Target" : "Sweep");

        M5.Lcd.setTextColor(YELLOW);
        M5.Lcd.fillRoundRect(5, M5.Lcd.height() - 25, 35, 20, 4, 0x4208);
        M5.Lcd.drawString("M5", 15, M5.Lcd.height() - 22);

        int boxX = 5;
        int boxY = 110;
        int boxWidth = M5.Lcd.width()/2 - 15;
        int boxHeight = 50;
        
        M5.Lcd.fillRoundRect(boxX, boxY, boxWidth, boxHeight, 4, 0x2104);
        M5.Lcd.setTextColor(WHITE);
        
        if (jammerTargetMode) {
            M5.Lcd.drawString("TARGET", boxX + 5, boxY + 5);
            M5.Lcd.drawFloat(targetJamFrequency, 2, boxX + 5, boxY + 20);
            M5.Lcd.drawString("MHz", boxX + 50, boxY + 20);

            int centerX = boxX + boxWidth/2;
            M5.Lcd.fillTriangle(
                centerX - 25, boxY + boxHeight - 5,
                centerX + 25, boxY + boxHeight - 5,
                centerX, boxY + boxHeight - 25,
                RED
            );
        } else {
            M5.Lcd.drawString("SWEEP", boxX + 5, boxY + 5);

            int waveY = boxY + 30;
            for (int x = boxX + 5; x < boxX + boxWidth - 5; x += 3) {
                int offset = 10 * sin((x - boxX) * 0.1);
                M5.Lcd.drawPixel(x, waveY + offset, RED);
                M5.Lcd.drawPixel(x, waveY + offset - 1, RED);
                M5.Lcd.drawPixel(x, waveY + offset + 1, RED);
            }
        }
        
        firstRun = false;
        pinMode(rf_transmit_pin, OUTPUT);
    }

    if (millis() - lastUpdate > 500) {
        int rightMargin = M5.Lcd.width()/2 + 8;
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(RED);
        M5.Lcd.setCursor(rightMargin + 5, 28);
        M5.Lcd.printf("%.2f", jammerTargetMode ? targetJamFrequency : JAM_FREQUENCY);
        M5.Lcd.setTextSize(1);
        M5.Lcd.setCursor(rightMargin + 5, 43);
        M5.Lcd.print("MHz");

        int barWidth = 70;
        int randomWidth = random(barWidth - 10, barWidth);
        M5.Lcd.fillRect(rightMargin + 5, 72, 70, 12, BLACK);
        M5.Lcd.fillRect(rightMargin + 5, 72, randomWidth, 12, RED);
        M5.Lcd.drawRect(rightMargin + 5, 72, 70, 12, 0x4208);

        M5.Lcd.fillRect(rightMargin + 5, 115, 70, 20, 0x4208);
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.setCursor(rightMargin + 5, 115);
        M5.Lcd.print(jamCount);
        
        lastUpdate = millis();
    }
    
    if (jammerTargetMode) {
        for(int i = 0; i < 255; i++) {
            digitalWrite(rf_transmit_pin, HIGH);
            delayMicroseconds(round(1000000/targetJamFrequency));
            digitalWrite(rf_transmit_pin, LOW);
            delayMicroseconds(round(1000000/targetJamFrequency));
        }
    } else {
        for(int i = 0; i < 255; i++) {
            digitalWrite(rf_transmit_pin, HIGH);
            delayMicroseconds(random(1, 3));
            digitalWrite(rf_transmit_pin, LOW);
            delayMicroseconds(random(1, 3));
        }
    }
    
    jamCount++;

    if (M5.BtnA.wasPressed()) {
        inJammerModeOverlay = true;
        displayJammerModeOverlay();
    }
}

void displayJammerModeOverlay() {
    int overlayWidth = 160;
    int overlayHeight = 120;
    int x = (M5.Lcd.width() - overlayWidth) / 2;
    int y = (M5.Lcd.height() - overlayHeight) / 2;

    int selectedMode = jammerTargetMode ? 1 : 0;
    
    while (inJammerModeOverlay) {
        M5.Lcd.fillRoundRect(x, y, overlayWidth, overlayHeight, 8, 0x4208);
        M5.Lcd.drawRoundRect(x, y, overlayWidth, overlayHeight, 8, WHITE);
        
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.drawString("JAM MODE", x + 35, y + 10);
        
        M5.Lcd.drawLine(x + 10, y + 30, x + overlayWidth - 10, y + 30, WHITE);

        for (int i = 0; i < 2; i++) {
            int optionY = y + 45 + (i * 30);
            const char* modeText = (i == 0) ? "Sweep" : "Target";
            
            if (i == selectedMode) {
                M5.Lcd.fillRoundRect(x + 20, optionY - 2, overlayWidth - 40, 25, 4, WHITE);
                M5.Lcd.setTextColor(BLACK);
            } else {
                M5.Lcd.drawRoundRect(x + 20, optionY - 2, overlayWidth - 40, 25, 4, WHITE);
                M5.Lcd.setTextColor(WHITE);
            }
            
            int textWidth = M5.Lcd.textWidth(modeText);
            int textX = x + (overlayWidth - textWidth) / 2;
            M5.Lcd.drawString(modeText, textX, optionY);
        }

        M5.update();
        
        if (M5.BtnB.wasPressed()) {
            selectedMode = 1 - selectedMode;
        }
        
        if (M5.BtnA.wasPressed()) {
            jammerTargetMode = (selectedMode == 1);
            
            if (jammerTargetMode) {
                displayTargetFrequencyOverlay();
            } else {
                inJammerModeOverlay = false;
                return;
            }
        }
        
        if (M5.BtnPWR.wasPressed()) {
            inJammerModeOverlay = false;
            return;
        }
        
        delay(50);
    }
}
void displayTargetFrequencyOverlay() {
    int overlayWidth = 180;
    int overlayHeight = 140;
    int x = (M5.Lcd.width() - overlayWidth) / 2;
    int y = (M5.Lcd.height() - overlayHeight) / 2;

    int selectedFreqIndex = currentTargetFreqIndex;
    
    while (true) {
        M5.Lcd.fillRoundRect(x, y, overlayWidth, overlayHeight, 8, 0x4208);
        M5.Lcd.drawRoundRect(x, y, overlayWidth, overlayHeight, 8, WHITE);
        
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.drawString("FREQUENCY", x + 30, y + 10);
        
        M5.Lcd.drawLine(x + 10, y + 30, x + overlayWidth - 10, y + 30, WHITE);

        for (int i = 0; i < numTargetFrequencies; i++) {
            int optionY = y + 40 + (i * 20);
            char freqText[10];
            sprintf(freqText, "%.2f MHz", targetFrequencies[i]);
            
            if (i == selectedFreqIndex) {
                M5.Lcd.fillRoundRect(x + 15, optionY - 2, overlayWidth - 30, 18, 4, WHITE);
                M5.Lcd.setTextColor(BLACK);
            } else {
                M5.Lcd.setTextColor(WHITE);
            }
            
            M5.Lcd.setTextSize(1);
            M5.Lcd.drawString(freqText, x + 25, optionY);
        }

        M5.update();
        
        if (M5.BtnB.wasPressed()) {
            selectedFreqIndex = (selectedFreqIndex + 1) % numTargetFrequencies;
        }
        
        if (M5.BtnA.wasPressed()) {
            currentTargetFreqIndex = selectedFreqIndex;
            targetJamFrequency = targetFrequencies[selectedFreqIndex];

            inJammerModeOverlay = false;
            return;
        }
        
        if (M5.BtnPWR.wasPressed()) {
            return;
        }
        
        delay(50);
    }
}
void handlePacketMonitor() {
    static unsigned long lastDraw = 0;
    
    if (millis() - lastCounterUpdate >= 1000) {
        packetsPerSecond = totalPackets - lastPacketCount;
        lastPacketCount = totalPackets;
        lastCounterUpdate = millis();
    }
    
    if (millis() - lastDraw >= 100) {
        drawPacketMonitorScreen();
        lastDraw = millis();
    }
    
    if (M5.BtnB.wasPressed()) {
        currentWiFiChannel = (currentWiFiChannel % 14) + 1;
        esp_wifi_set_channel(currentWiFiChannel, WIFI_SECOND_CHAN_NONE);
    }
    
    if (M5.BtnPWR.wasPressed()) {
        inPacketMonitor = false;
        WiFi.mode(WIFI_STA);
        inSubmenu = true;
        displaySubMenu();
    }
}

void drawPacketMonitorScreen() {
    M5.Lcd.fillScreen(BLACK);
    drawHeader();

    const int GRAPH_X = 5;
    const int GRAPH_Y = 25;
    const int GRAPH_W = M5.Lcd.width() - 10;
    const int GRAPH_H = 80;
    
    M5.Lcd.drawRect(GRAPH_X, GRAPH_Y, GRAPH_W, GRAPH_H, 0x4208);

    for (int i = 0; i < PACKET_HISTORY_SIZE - 1; i++) {
        int x1 = map(i, 0, PACKET_HISTORY_SIZE - 1, GRAPH_X + 1, GRAPH_X + GRAPH_W - 2);
        int x2 = map(i + 1, 0, PACKET_HISTORY_SIZE - 1, GRAPH_X + 1, GRAPH_X + GRAPH_W - 2);

        int y1 = constrain(map(packetHistory[i], 0, 100, GRAPH_Y + GRAPH_H - 2, GRAPH_Y + 1), GRAPH_Y + 1, GRAPH_Y + GRAPH_H - 2);
        int y2 = constrain(map(packetHistory[(i + 1)], 0, 100, GRAPH_Y + GRAPH_H - 2, GRAPH_Y + 1), GRAPH_Y + 1, GRAPH_Y + GRAPH_H - 2);
        
        uint16_t color = CYAN;
        if (packetHistory[i] > 50) color = YELLOW;
        if (packetHistory[i] > 80) color = RED;
        
        M5.Lcd.drawLine(x1, y1, x2, y2, color);
    }

    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(WHITE);
    
    M5.Lcd.drawString("CH: " + String(currentWiFiChannel), 10, 110);
    M5.Lcd.drawString("PPS: " + String(packetsPerSecond), 10, 125);
    M5.Lcd.drawString("PKTs: " + String(totalPackets), M5.Lcd.width()/2 + 10, 110);

    M5.Lcd.fillRoundRect(M5.Lcd.width()/2 + 10, 125, 30, 15, 4, 0x4208);
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.drawString(String(currentWiFiChannel), M5.Lcd.width()/2 + 20, 127);
}

void handleWiFiScan() {
    static bool firstRun = true;
    static int currentNetwork = 0;
    static int networkCount = 0;
    static WiFiScanResult* networks = nullptr;
    
    if (firstRun) {
        M5.Lcd.fillScreen(BLACK);
        drawHeader();
        
        M5.Lcd.setTextSize(2);
        String scanText = "Scanning WiFi";
        int textWidth = M5.Lcd.textWidth(scanText);
        int centerX = (M5.Lcd.width() - textWidth) / 2;
        int centerY = M5.Lcd.height() / 2 - 10;
        
        M5.Lcd.fillRoundRect(20, centerY - 20, M5.Lcd.width() - 40, 60, 8, 0x2104);
        M5.Lcd.setTextColor(CYAN);
        M5.Lcd.drawString(scanText, centerX, centerY);
        
        for(int i = 0; i < 6; i++) {
            M5.Lcd.fillCircle(40 + (i * 15), M5.Lcd.height()/2 + 10, 3, CYAN);
            delay(200);
        }
        
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
        delay(100);

        int validNetworks = 0;
        int totalNetworks = WiFi.scanNetworks();
        
        for(int i = 0; i < totalNetworks; i++) {
            if(WiFi.channel(i) <= 14) {
                validNetworks++;
            }
        }
        
        networkCount = validNetworks;
        if (networks) delete[] networks;
        networks = new WiFiScanResult[networkCount];
        
        int networkIndex = 0;
        for(int i = 0; i < totalNetworks; i++) {
            if(WiFi.channel(i) <= 14) {
                networks[networkIndex].ssid = WiFi.SSID(i).length() > 0 ? WiFi.SSID(i) : "Hidden Network";
                networks[networkIndex].rssi = WiFi.RSSI(i);
                networks[networkIndex].channel = WiFi.channel(i);
                networks[networkIndex].encType = WiFi.encryptionType(i);
                memcpy(networks[networkIndex].bssid, WiFi.BSSID(i), 6);
                networkIndex++;
            }
        }
        
        WiFi.scanDelete();
        firstRun = false;
        
        if(networkCount > 0) {
            displayNetwork(currentNetwork, networkCount, &networks[currentNetwork]);
        } else {
            M5.Lcd.fillScreen(BLACK);
            drawHeader();
            M5.Lcd.setTextSize(2);
            M5.Lcd.setTextColor(RED);
            M5.Lcd.drawString("No Networks", 30, M5.Lcd.height()/2);
        }
    }
    
    if (M5.BtnB.wasPressed() && networkCount > 0) {
        currentNetwork = (currentNetwork + 1) % networkCount;
        displayNetwork(currentNetwork, networkCount, &networks[currentNetwork]);
    }
    
    if (M5.BtnPWR.wasPressed()) {
        if (networks) {
            delete[] networks;
            networks = nullptr;
        }
        inWiFiScan = false;
        inSubmenu = true;
        firstRun = true;
        displaySubMenu();
    }
}

void handleActionOverlay() {
    if (M5.BtnA.wasPressed()) {
        if (inIrRemoteMenu) {
            spamIRCodes(currentDeviceType, currentSubMenuItem);
            inActionOverlay = false;
            displaySubMenu();
        } else if (currentMenuItem == 1 && currentSubMenuItem == 4) {
            handleDeauthAction(false);
        }
    }
}

void handleDeauthAction(bool target) {
    if (target) {
    } else {
    }
}

void displayNetwork(int index, int total, WiFiScanResult* networks) {
    M5.Lcd.fillScreen(BLACK);
    drawHeader();

    int cardX = 5;
    int cardY = 25;
    int cardWidth = M5.Lcd.width() - 10;
    int cardHeight = M5.Lcd.height() - 35;
    
    M5.Lcd.fillRoundRect(cardX, cardY, cardWidth, cardHeight, 8, 0x2104);
    M5.Lcd.drawRoundRect(cardX, cardY, cardWidth, cardHeight, 8, CYAN);
    
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(WHITE);

    String ssid = networks[index].ssid;
    if(ssid.length() > 16) ssid = ssid.substring(0, 16) + "...";
    M5.Lcd.fillRoundRect(cardX + 5, cardY + 5, cardWidth - 10, 20, 4, 0x4208);
    M5.Lcd.drawString(ssid, cardX + 10, cardY + 8);

    int signalStrength = min(100, (int)(2 * (networks[index].rssi + 100)));
    int barWidth = map(signalStrength, 0, 100, 0, cardWidth - 70);
    M5.Lcd.fillRoundRect(cardX + 10, cardY + 30, cardWidth - 70, 8, 2, 0x4208);
    M5.Lcd.fillRoundRect(cardX + 10, cardY + 30, barWidth, 8, 2, GREEN);
    M5.Lcd.drawString(String(signalStrength) + "%", cardX + cardWidth - 50, cardY + 28);

    int col1X = cardX + 10;
    int col2X = cardX + cardWidth/2;
    int startY = cardY + 45;
    int lineHeight = 18;
    
    M5.Lcd.drawString("Ch: " + String(networks[index].channel), col1X, startY);
    M5.Lcd.drawString("dB: " + String(networks[index].rssi), col2X, startY);
    
    M5.Lcd.drawString("Band: " + String(networks[index].channel > 14 ? "5GHz" : "2.4GHz"), col1X, startY + lineHeight);
    M5.Lcd.drawString("Sec: " + String(getEncryptionType(networks[index].encType)), col2X, startY + lineHeight);

    M5.Lcd.drawString("MAC:", col1X, startY + lineHeight * 2);
    char macStr[18];
    sprintf(macStr, "%02X:%02X:%02X:%02X:%02X:%02X", 
            networks[index].bssid[0], networks[index].bssid[1], networks[index].bssid[2],
            networks[index].bssid[3], networks[index].bssid[4], networks[index].bssid[5]);
    M5.Lcd.drawString(macStr, col1X + 35, startY + lineHeight * 2);

    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.drawString(String(index + 1) + "/" + String(total), cardX + cardWidth - 40, cardY + cardHeight - 15);
}

void handleBleScanner() {
    static bool hasScanned = false;
    static unsigned long lastScanTime = 0;
    static const unsigned long SCAN_TIMEOUT = 60000;

    if (hasScanned && (millis() - lastScanTime > SCAN_TIMEOUT)) {
        hasScanned = false;
    }
    
    if (!hasScanned) {
        M5.Lcd.fillScreen(BLACK);
        drawHeader();
        
        M5.Lcd.setTextSize(2);
        String scanText = "Scanning BLE";
        int textWidth = M5.Lcd.textWidth(scanText);
        int centerX = (M5.Lcd.width() - textWidth) / 2;
        int centerY = M5.Lcd.height() / 2 - 10;
        
        M5.Lcd.fillRoundRect(20, centerY - 20, M5.Lcd.width() - 40, 60, 8, 0x2104);
        M5.Lcd.setTextColor(CYAN);
        M5.Lcd.drawString(scanText, centerX, centerY);

        if (bleDevices) {
            delete[] bleDevices;
            bleDevices = nullptr;
        }

        BLEDevice::init("");
        BLEScan* pBLEScan = BLEDevice::getScan();
        pBLEScan->setActiveScan(true);

        BLEScanResults results = pBLEScan->start(3);
        yield();

        bleDeviceCount = results.getCount();

        int maxDevices = min(bleDeviceCount, 50);
        
        if (maxDevices > 0) {
            bleDevices = new BLEDeviceInfo[maxDevices];

            for(int i = 0; i < maxDevices; i++) {
                BLEAdvertisedDevice device = results.getDevice(i);
                bleDevices[i].name = device.getName().c_str();
                if (bleDevices[i].name.length() == 0) {
                    bleDevices[i].name = "Unknown Device";
                }
                bleDevices[i].address = device.getAddress().toString().c_str();
                bleDevices[i].rssi = device.getRSSI();
                bleDevices[i].type = "BLE";
                bleDevices[i].isConnectable = true;
            }

            bleDeviceCount = maxDevices;
        }

        pBLEScan->clearResults();
        
        hasScanned = true;
        lastScanTime = millis();
        currentBleDevice = 0;

        if (bleDeviceCount > 0) {
            displayBleDevice(currentBleDevice, bleDeviceCount, &bleDevices[currentBleDevice]);
        } else {
            M5.Lcd.fillScreen(BLACK);
            drawHeader();
            M5.Lcd.setTextSize(2);
            M5.Lcd.setTextColor(RED);
            M5.Lcd.drawString("No BLE Devices", 30, M5.Lcd.height()/2);
        }
    }

    static unsigned long lastYieldTime = 0;
    if (millis() - lastYieldTime > 100) {
        yield();
        lastYieldTime = millis();
    }

    if (M5.BtnB.wasPressed() && bleDeviceCount > 0) {
        currentBleDevice = (currentBleDevice + 1) % bleDeviceCount;
        displayBleDevice(currentBleDevice, bleDeviceCount, &bleDevices[currentBleDevice]);
    }

    if (M5.BtnA.wasPressed()) {
        hasScanned = false;
    }

    if (M5.BtnPWR.wasPressed()) {
        inBleScanner = false;
        inSubmenu = false;
        hasScanned = false;

        if (bleDevices) {
            delete[] bleDevices;
            bleDevices = nullptr;
        }
        
        displayMenuItem();
    }
}

void displayIrModsOverlay() {
    inIrModsOverlay = true;
    currentIrModOption = 0;
    drawIrModsOverlay();
}

void drawIrModsOverlay() {
    int overlayWidth = 160;
    int overlayHeight = 120;
    int x = (M5.Lcd.width() - overlayWidth) / 2;
    int y = (M5.Lcd.height() - overlayHeight) / 2;
    
    M5.Lcd.fillRoundRect(x, y, overlayWidth, overlayHeight, 8, 0x4208);
    M5.Lcd.drawRoundRect(x, y, overlayWidth, overlayHeight, 8, WHITE);
    
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(WHITE);
    int titleWidth = M5.Lcd.textWidth("IR MODS");
    M5.Lcd.drawString("IR MODS", x + (overlayWidth - titleWidth) / 2, y + 10);
    
    M5.Lcd.drawLine(x + 10, y + 30, x + overlayWidth - 10, y + 30, WHITE);
    
    for (int i = 0; i < numIrModOptions; i++) {
        int optionY = y + 40 + (i * 25);
        
        if (i == currentIrModOption) {
            M5.Lcd.fillRoundRect(x + 10, optionY - 2, overlayWidth - 20, 20, 4, WHITE);
            M5.Lcd.setTextColor(BLACK);
        } else {
            M5.Lcd.setTextColor(WHITE);
        }
        
        int textWidth = M5.Lcd.textWidth(irModOptions[i]);
        int textX = x + (overlayWidth - textWidth) / 2;
        M5.Lcd.drawString(irModOptions[i], textX, optionY);
    }
}

void handleIrModsOverlay() {
    if (M5.BtnB.wasPressed()) {
        currentIrModOption = (currentIrModOption + 1) % numIrModOptions;
        drawIrModsOverlay();
    }
    
    if (M5.BtnA.wasPressed()) {
        switch (currentIrModOption) {
            case 0:
            ir_send_pin = 19;
            ir_receive_pin = 33;
                break;
            case 1:
                ir_send_pin = 32;
                ir_receive_pin = 33;
                break;
            case 2:
                ir_send_pin = 19;
                ir_receive_pin = 26;
                break;
        }

        IrSender.begin(ir_send_pin);

        int x = M5.Lcd.width() / 2 - 50;
        int y = M5.Lcd.height() - 30;
        M5.Lcd.fillRoundRect(x, y, 100, 20, 4, GREEN);
        M5.Lcd.setTextColor(BLACK);
        M5.Lcd.setTextSize(1);
        M5.Lcd.drawString("APPLIED!", x + 25, y + 5);
        delay(1000);
        
        inIrModsOverlay = false;
        displaySubMenu();
    }
    
    if (M5.BtnPWR.wasPressed()) {
        inIrModsOverlay = false;
        displaySubMenu();
    }
}

void displayRfModsOverlay() {
    inRfModsOverlay = true;
    currentRfModOption = 0;
    drawRfModsOverlay();
}

void handleRfModsOverlay() {
    if (M5.BtnB.wasPressed()) {
        currentRfModOption = (currentRfModOption + 1) % numRfModOptions;
        drawRfModsOverlay();
    }
    
    if (M5.BtnA.wasPressed()) {

        switch (currentRfModOption) {
            case 0:
                rf_transmit_pin = 32;
                rf_receiver_pin = 33;
                current_rf_frequency = 433.92;
                currentRfModule = 1;
                break;
                
            case 1:
                rf_transmit_pin = 26;
                rf_receiver_pin = 26;
                current_rf_frequency = 433.92;
                currentRfModule = 2;
                break;
                
            case 2:
                current_rf_frequency = 433.92; 
                currentRfModule = 3;
                break;
        }

        int x = M5.Lcd.width() / 2 - 50;
        int y = M5.Lcd.height() - 30;
        M5.Lcd.fillRoundRect(x, y, 100, 20, 4, GREEN);
        M5.Lcd.setTextColor(BLACK);
        M5.Lcd.setTextSize(1);
        M5.Lcd.drawString("APPLIED!", x + 25, y + 5);
        delay(1000);
        
        inRfModsOverlay = false;
        displaySubMenu();
    }
    
    if (M5.BtnPWR.wasPressed()) {
        inRfModsOverlay = false;
        displaySubMenu();
    }
}

void drawRfModsOverlay() {
    int overlayWidth = 160;
    int overlayHeight = 120;
    int x = (M5.Lcd.width() - overlayWidth) / 2;
    int y = (M5.Lcd.height() - overlayHeight) / 2;
    
    M5.Lcd.fillRoundRect(x, y, overlayWidth, overlayHeight, 8, 0x4208);
    M5.Lcd.drawRoundRect(x, y, overlayWidth, overlayHeight, 8, WHITE);
    
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(WHITE);
    int titleWidth = M5.Lcd.textWidth("RF MODS");
    M5.Lcd.drawString("RF MODS", x + (overlayWidth - titleWidth) / 2, y + 10);
    
    M5.Lcd.drawLine(x + 10, y + 30, x + overlayWidth - 10, y + 30, WHITE);
    
    for (int i = 0; i < numRfModOptions; i++) {
        int optionY = y + 40 + (i * 25);
        
        if (i == currentRfModOption) {
            M5.Lcd.fillRoundRect(x + 10, optionY - 2, overlayWidth - 20, 20, 4, WHITE);
            M5.Lcd.setTextColor(BLACK);
        } else {
            M5.Lcd.setTextColor(WHITE);
        }
        
        int textWidth = M5.Lcd.textWidth(rfModOptions[i]);
        int textX = x + (overlayWidth - textWidth) / 2;
        M5.Lcd.drawString(rfModOptions[i], textX, optionY);
    }
}

void displayFixedFqOverlay() {
    inFixedFqOverlay = true;
    inCustomFqOverlay = false;
    currentFixedFqOption = 0;
    drawFixedFqOverlay();
}

void drawFixedFqOverlay() {
    int overlayWidth = 180;
    int overlayHeight = 150;
    int x = (M5.Lcd.width() - overlayWidth) / 2;
    int y = (M5.Lcd.height() - overlayHeight) / 2;
    
    M5.Lcd.fillScreen(BLACK);
    drawHeader();
    
    M5.Lcd.fillRoundRect(x, y, overlayWidth, overlayHeight, 8, 0x4208);
    M5.Lcd.drawRoundRect(x, y, overlayWidth, overlayHeight, 8, WHITE);
    
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(WHITE);
    int titleWidth = M5.Lcd.textWidth("FIXED FQ");
    M5.Lcd.drawString("FIXED FQ", x + (overlayWidth - titleWidth) / 2, y + 10);
    
    M5.Lcd.drawLine(x + 10, y + 30, x + overlayWidth - 10, y + 30, WHITE);
    
    const int visibleItems = 4;
    int startIndex = max(0, currentFixedFqOption - (visibleItems / 2));
    startIndex = min(startIndex, numFixedFrequencies - visibleItems);
    startIndex = max(0, startIndex);
    
    for (int i = 0; i < min(visibleItems, numFixedFrequencies); i++) {
        int itemIndex = startIndex + i;
        if (itemIndex >= numFixedFrequencies) break;
        
        int optionY = y + 40 + (i * 25);
        
        if (itemIndex == currentFixedFqOption) {
            M5.Lcd.fillRoundRect(x + 10, optionY - 2, overlayWidth - 20, 20, 4, WHITE);
            M5.Lcd.setTextColor(BLACK);
        } else {
            M5.Lcd.setTextColor(WHITE);
        }
        
        String freqText = String(fixedFrequencies[itemIndex], 3) + " MHz";
        int textWidth = M5.Lcd.textWidth(freqText);
        int textX = x + (overlayWidth - textWidth) / 2;
        M5.Lcd.drawString(freqText, textX, optionY);
    }

    if (startIndex > 0) {
        M5.Lcd.setTextColor(CYAN);
        M5.Lcd.drawString("▲", x + overlayWidth - 20, y + 35);
    }
    
    if (startIndex + visibleItems < numFixedFrequencies) {
        M5.Lcd.setTextColor(CYAN);
        M5.Lcd.drawString("▼", x + overlayWidth - 20, y + overlayHeight - 25);
    }
}

void displayCustomFqOverlay() {
    inCustomFqOverlay = true;
    currentCustomFqOption = 0;
    drawCustomFqOverlay();
}

void drawCustomFqOverlay() {
    int overlayWidth = 180;
    int overlayHeight = 120;
    int x = (M5.Lcd.width() - overlayWidth) / 2;
    int y = (M5.Lcd.height() - overlayHeight) / 2;
    
    M5.Lcd.fillRoundRect(x, y, overlayWidth, overlayHeight, 8, 0x4208);
    M5.Lcd.drawRoundRect(x, y, overlayWidth, overlayHeight, 8, WHITE);
    
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(WHITE);
    int titleWidth = M5.Lcd.textWidth("FREQUENCY");
    M5.Lcd.drawString("FREQUENCY", x + (overlayWidth - titleWidth) / 2, y + 10);
    
    M5.Lcd.drawLine(x + 10, y + 30, x + overlayWidth - 10, y + 30, WHITE);
    
    for (int i = 0; i < numCustomFqOptions; i++) {
        int optionY = y + 40 + (i * 25);
        
        if (i == currentCustomFqOption) {
            M5.Lcd.fillRoundRect(x + 10, optionY - 2, overlayWidth - 20, 20, 4, WHITE);
            M5.Lcd.setTextColor(BLACK);
        } else {
            M5.Lcd.setTextColor(WHITE);
        }
        
        int textWidth = M5.Lcd.textWidth(customFqOptions[i]);
        int textX = x + (overlayWidth - textWidth) / 2;
        M5.Lcd.drawString(customFqOptions[i], textX, optionY);
    }
}

void handleCustomFqOverlay() {
    if (M5.BtnB.wasPressed()) {
        currentCustomFqOption = (currentCustomFqOption + 1) % numCustomFqOptions;
        drawCustomFqOverlay();
    }
    
    if (M5.BtnA.wasPressed()) {
        switch (currentCustomFqOption) {
            case 0:
                selectedFrequency = 433.92;
                break;
                
            case 1:
                break;
                
            case 2:
                displayFixedFqOverlay();
                return;
        }
        

        int x = M5.Lcd.width() / 2 - 50;
        int y = M5.Lcd.height() - 30;
        M5.Lcd.fillRoundRect(x, y, 100, 20, 4, GREEN);
        M5.Lcd.setTextColor(BLACK);
        M5.Lcd.setTextSize(1);
        M5.Lcd.drawString("APPLIED!", x + 25, y + 5);
        delay(1000);
        
        inCustomFqOverlay = false;
        displaySubMenu();
    }
    
    if (M5.BtnPWR.wasPressed()) {
        inCustomFqOverlay = false;
        displaySubMenu();
    }
}

void handleFixedFqOverlay() {
    if (M5.BtnB.wasPressed()) {
        currentFixedFqOption = (currentFixedFqOption + 1) % numFixedFrequencies;
        drawFixedFqOverlay();
    }
    
    if (M5.BtnA.wasPressed()) {
        selectedFrequency = fixedFrequencies[currentFixedFqOption];
        
        M5.Lcd.fillScreen(BLACK);
        drawHeader();
        
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(GREEN);
        M5.Lcd.drawString("FREQUENCY SET", 20, 60);
        
        String freqText = String(selectedFrequency, 3) + " MHz";
        int textWidth = M5.Lcd.textWidth(freqText);
        int centerX = (M5.Lcd.width() - textWidth) / 2;
        M5.Lcd.drawString(freqText, centerX, 90);
        
        delay(1500);
        inFixedFqOverlay = false;
        displaySubMenu();
    }
    
    if (M5.BtnPWR.wasPressed()) {
        inFixedFqOverlay = false;
        inCustomFqOverlay = true;
        drawCustomFqOverlay();
    }
}

void displayBleDevice(int index, int total, BLEDeviceInfo* devices) {
    M5.Lcd.fillScreen(BLACK);
    drawHeader();
    
    int cardX = 5;
    int cardY = 25;
    int cardWidth = M5.Lcd.width() - 10;
    int cardHeight = M5.Lcd.height() - 35;
    
    M5.Lcd.fillRoundRect(cardX, cardY, cardWidth, cardHeight, 8, 0x2104);
    M5.Lcd.drawRoundRect(cardX, cardY, cardWidth, cardHeight, 8, CYAN);
    
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(WHITE);
    
    String name = devices[index].name;
    if(name.length() > 16) name = name.substring(0, 16) + "...";
    
    M5.Lcd.fillRoundRect(cardX + 5, cardY + 5, cardWidth - 10, 20, 4, 0x4208);
    M5.Lcd.drawString(name, cardX + 10, cardY + 8);
    
    int signalStrength = min(100, (int)(2 * (devices[index].rssi + 100)));
    int barWidth = map(signalStrength, 0, 100, 0, cardWidth - 70);
    M5.Lcd.fillRoundRect(cardX + 10, cardY + 30, cardWidth - 70, 8, 2, 0x4208);
    M5.Lcd.fillRoundRect(cardX + 10, cardY + 30, barWidth, 8, 2, GREEN);
    M5.Lcd.drawString(String(signalStrength) + "%", cardX + cardWidth - 50, cardY + 28);
    
    int col1X = cardX + 10;
    int col2X = cardX + cardWidth/2;
    int startY = cardY + 45;
    int lineHeight = 18;
    
    M5.Lcd.drawString("RSSI: " + String(devices[index].rssi) + "dB", col1X, startY);
    M5.Lcd.drawString("Type: BLE", col2X, startY);
    
    M5.Lcd.drawString("Status: Active", col1X, startY + lineHeight);
    
    M5.Lcd.drawString("Address:", col1X, startY + lineHeight * 2);
    M5.Lcd.drawString(devices[index].address, col1X + 55, startY + lineHeight * 2);
    
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.drawString(String(index + 1) + "/" + String(total), cardX + cardWidth - 40, cardY + cardHeight - 15);
}

void handleCardSkimmer() {
    static bool scanning = true;
    static unsigned long scanStartTime = 0;
    
    if (scanning) {
        scanStartTime = millis();
        M5.Lcd.fillScreen(BLACK);
        drawHeader();

        M5.Lcd.setTextSize(2);
        String scanText = "Scanning For";
        String scanText2 = "Card Skimmers";
        int textWidth = M5.Lcd.textWidth(scanText);
        int centerX = (M5.Lcd.width() - textWidth) / 2;
        
        M5.Lcd.fillRoundRect(20, 40, M5.Lcd.width() - 40, 80, 8, 0x2104);
        M5.Lcd.setTextColor(RED);
        M5.Lcd.drawString(scanText, centerX, 50);
        M5.Lcd.drawString(scanText2, centerX - 20, 80);

        skimmerCount = 2;
        if (skimmerDevices) delete[] skimmerDevices;
        skimmerDevices = new SkimmerDevice[skimmerCount];
        
        skimmerDevices[0] = {"RFID Skimmer", "125.0 KHz", -45, "EM4100", "9600", true};
        skimmerDevices[1] = {"NFC Skimmer", "13.56 MHz", -52, "ISO14443A", "106K", true};
        
        delay(3000);
        scanning = false;
        displaySkimmerInfo(currentSkimmer);
    }
    
    if (M5.BtnB.wasPressed() && skimmerCount > 0) {
        currentSkimmer = (currentSkimmer + 1) % skimmerCount;
        displaySkimmerInfo(currentSkimmer);
    }
    
    if (M5.BtnPWR.wasPressed()) {
        if (skimmerDevices) {
            delete[] skimmerDevices;
            skimmerDevices = nullptr;
        }
        inCardSkimmer = false;
        inSubmenu = false;
        displayMenuItem();
    }
}

void displaySkimmerInfo(int index) {
    M5.Lcd.fillScreen(BLACK);
    drawHeader();
    
    int cardX = 5;
    int cardY = 25;
    int cardWidth = M5.Lcd.width() - 10;
    int cardHeight = M5.Lcd.height() - 35;
    
    M5.Lcd.fillRoundRect(cardX, cardY, cardWidth, cardHeight, 8, 0x2104);
    M5.Lcd.drawRoundRect(cardX, cardY, cardWidth, cardHeight, 8, RED);
    
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(WHITE);
    
    M5.Lcd.fillRoundRect(cardX + 5, cardY + 5, cardWidth - 10, 20, 4, 0x4208);
    M5.Lcd.drawString("SKIMMER DETECTED!", cardX + 10, cardY + 8);
    
    int startY = cardY + 35;
    int lineHeight = 18;
    
    M5.Lcd.drawString("Type: " + skimmerDevices[index].deviceType, cardX + 10, startY);
    M5.Lcd.drawString("Freq: " + skimmerDevices[index].frequency, cardX + 10, startY + lineHeight);
    M5.Lcd.drawString("Protocol: " + skimmerDevices[index].protocol, cardX + 10, startY + lineHeight * 2);
    M5.Lcd.drawString("Data Rate: " + skimmerDevices[index].dataRate, cardX + 10, startY + lineHeight * 3);
    
    M5.Lcd.setTextColor(RED);
    M5.Lcd.drawString(String(index + 1) + "/" + String(skimmerCount), cardX + cardWidth - 40, cardY + cardHeight - 15);
}

void displayNoSkimmersFound() {
    M5.Lcd.fillScreen(BLACK);
    drawHeader();
    
    M5.Lcd.setTextSize(2);
    String message = "No Skimmers Found";
    int textWidth = M5.Lcd.textWidth(message);
    int centerX = (M5.Lcd.width() - textWidth) / 2;
    int centerY = M5.Lcd.height() / 2 - 10;
    
    M5.Lcd.fillRoundRect(20, centerY - 20, M5.Lcd.width() - 40, 60, 8, 0x2104);
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.drawString(message, centerX, centerY);
}

void handleColorSelection() {
    int selectedColor = 0;
    bool exitMenu = false;

    for (int i = 0; i < 5; i++) {
        if (themes[i].primary == currentTheme.primary) {
            selectedColor = i;
            break;
        }
    }
    
    while (!exitMenu) {
        M5.Lcd.fillScreen(BLACK);
        drawHeader();

        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.drawString("UI THEMES", 60, 30);

        M5.Lcd.fillRoundRect(20, 70, M5.Lcd.width()-40, 40, 8, themes[selectedColor].primary);

        if (themes[selectedColor].primary == BLACK || themes[selectedColor].primary == BLUE) {
            M5.Lcd.setTextColor(WHITE);
        } else {
            M5.Lcd.setTextColor(BLACK);
        }

        int textWidth = M5.Lcd.textWidth(themes[selectedColor].name);
        int centerX = (M5.Lcd.width() - textWidth) / 2;
        M5.Lcd.drawString(themes[selectedColor].name, centerX, 80);

        M5.Lcd.setTextSize(1);
        M5.Lcd.setTextColor(WHITE);
        char positionText[10];
        sprintf(positionText, "%d/5", selectedColor + 1);
        M5.Lcd.drawString(positionText, M5.Lcd.width()/2 - 10, 120);

        M5.Lcd.drawRect(20, 135, M5.Lcd.width()-40, 50, themes[selectedColor].accent);
        M5.Lcd.fillRect(21, 136, M5.Lcd.width()-42, 48, themes[selectedColor].background);

        M5.Lcd.setTextColor(themes[selectedColor].primary);
        M5.Lcd.drawString("Sample Menu", 45, 145);
        M5.Lcd.drawFastHLine(30, 160, M5.Lcd.width()-60, themes[selectedColor].secondary);
        M5.Lcd.fillCircle(M5.Lcd.width()-50, 155, 5, themes[selectedColor].accent);
        M5.Lcd.fillCircle(M5.Lcd.width()-35, 155, 5, themes[selectedColor].primary);

        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.drawString("APPLY", 20, 200);
        M5.Lcd.drawString("NEXT", 120, 200);
        M5.Lcd.drawString("BACK", 200, 200);

        bool buttonPressed = false;
        while (!buttonPressed) {
            M5.update();
            
            if (M5.BtnA.wasPressed()) {
                currentTheme = themes[selectedColor];

                M5.Lcd.fillScreen(currentTheme.background);
                M5.Lcd.setTextColor(currentTheme.primary);
                M5.Lcd.setTextSize(2);
                M5.Lcd.drawString("Theme Applied!", 30, 100);
                delay(1000);
                
                exitMenu = true;
                buttonPressed = true;
            }
            
            if (M5.BtnB.wasPressed()) {
                selectedColor = (selectedColor + 1) % 5;
                buttonPressed = true;
            }
            
            if (M5.BtnPWR.wasPressed()) {
                exitMenu = true;
                buttonPressed = true;
            }
            
            delay(50);
        }
    }

    inColorSelection = false;
    inSubmenu = true;
    displaySubMenu();
}

void handleCredits() {
    static int scrollPosition = 0;
    static const int SCROLL_AMOUNT = 10;
    static const int MAX_SCROLL = 100;
    static const char* creditsText = "Signal X Network Team:\n\n"
        "D1Goat:Main Dev\n\n"
        "Hecker:Owner/dev\n\n"
        "SgtFlxy:WebFlasher Dev";

    M5.Lcd.fillScreen(BLACK);
    drawHeader();
    
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(currentTheme.primary);
    M5.Lcd.setTextWrap(true);

    const int textStartY = 25;
    const int visibleHeight = M5.Lcd.height() - textStartY;

    M5.Lcd.setCursor(5, textStartY - scrollPosition);
    M5.Lcd.print(creditsText);
    
    if (M5.BtnB.wasPressed()) {
        scrollPosition = min(scrollPosition + SCROLL_AMOUNT, MAX_SCROLL);
    }
    
    if (M5.BtnPWR.wasPressed()) {
        scrollPosition = 0;
        inSubmenu = false;
        displayMenuItem();
    }
}

void handleTimeDisplay() {
    static unsigned long lastUpdate = 0;
    static bool exitRequested = false;
    
    if (lastUpdate == 0) {
        M5.Lcd.fillScreen(BLACK);
        drawHeader();
        
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.drawString("DEVICE UPTIME", 25, 30);
        
        M5.Lcd.drawLine(10, 55, M5.Lcd.width() - 10, 55, currentTheme.accent);
        
        lastUpdate = millis();
    }

    if (millis() - lastUpdate >= 1000) {
        unsigned long uptime = millis();
        unsigned long seconds = uptime / 1000;
        unsigned long minutes = seconds / 60;
        unsigned long hours = minutes / 60;
        unsigned long days = hours / 24;
        
        seconds %= 60;
        minutes %= 60;
        hours %= 24;
        
        M5.Lcd.fillRect(20, 60, M5.Lcd.width() - 40, 80, BLACK);
        
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(CYAN);
        
        char timeStr[30];
        sprintf(timeStr, "%ld days", days);
        M5.Lcd.drawString(timeStr, 30, 70);
        
        sprintf(timeStr, "%02ld:%02ld:%02ld", hours, minutes, seconds);
        M5.Lcd.drawString(timeStr, 30, 100);
        
        lastUpdate = millis();
    }
    
    M5.update();
    if (M5.BtnPWR.wasPressed()) {
        lastUpdate = 0;
        inSubmenu = true;
        displaySubMenu();
    }
}

void handleFileSystem() {
    M5.Lcd.fillScreen(BLACK);
    drawHeader();

    M5.Lcd.drawFastVLine(M5.Lcd.width()/2, 21, M5.Lcd.height()-21, WHITE);

    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(WHITE);

    const size_t totalBytes = 3 * 1024;
    size_t usedBytes = SPIFFS.usedBytes();
    size_t freeBytes = totalBytes - usedBytes;

    M5.Lcd.drawString("Storage Info:", 5, 30);
    M5.Lcd.drawString("Total: 3KB", 5, 50);
    M5.Lcd.drawString("Used: " + String(usedBytes/1024) + "KB", 5, 70);
    M5.Lcd.drawString("Free: " + String(freeBytes/1024) + "KB", 5, 90);

    int barWidth = M5.Lcd.width()/2 - 20;
    int barHeight = 20;
    int barY = 110;
    
    M5.Lcd.drawRect(5, barY, barWidth, barHeight, WHITE);
    int usedWidth = map(usedBytes, 0, totalBytes, 0, barWidth);
    M5.Lcd.fillRect(5, barY, usedWidth, barHeight, RED);

    int rightX = M5.Lcd.width()/2 + 5;
    int dirY = 30;
    int spacing = 35;
    
    M5.Lcd.fillRoundRect(rightX, dirY, 100, 25, 4, 0x4208);
    M5.Lcd.drawString("IR Files", rightX + 5, dirY + 5);
    
    M5.Lcd.fillRoundRect(rightX, dirY + spacing, 100, 25, 4, 0x4208);
    M5.Lcd.drawString("RF Files", rightX + 5, dirY + spacing + 5);
    
    M5.Lcd.fillRoundRect(rightX, dirY + spacing * 2, 100, 25, 4, 0x4208);
    M5.Lcd.drawString("Files", rightX + 5, dirY + spacing * 2 + 5);
}

void handleIrReplay() {
    static bool firstRun = true;
    static unsigned long animationTimer = 0;
    static int dotCount = 0;
    static uint16_t rawData[100];
    static uint16_t rawLength = 0;
    static uint8_t protocol = 0;
    static uint32_t address = 0;
    static uint32_t command = 0;
    
    if (firstRun) {
        M5.Lcd.fillScreen(BLACK);
        drawHeader();

        M5.Lcd.drawRoundRect(10, 35, M5.Lcd.width()-20, 80, 8, currentTheme.accent);
        M5.Lcd.drawRoundRect(11, 36, M5.Lcd.width()-22, 78, 8, currentTheme.primary);
        
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(currentTheme.primary);
        M5.Lcd.drawString("IR SCANNER", 30, 45);
        
        M5.Lcd.fillRoundRect(20, 75, M5.Lcd.width()-40, 30, 4, 0x2104);
        M5.Lcd.setTextSize(1);
        M5.Lcd.drawString("Freq: 38kHz", M5.Lcd.width()-80, 40);

        IrReceiver.begin(ir_receive_pin, true);
        firstRun = false;
    }

    if (millis() - animationTimer > 300) {
        M5.Lcd.fillRoundRect(30, 82, M5.Lcd.width()-60, 16, 2, 0x2104);
        M5.Lcd.setTextColor(CYAN);
        String dots = "SCANNING";
        for(int i = 0; i < dotCount; i++) dots += ".";
        M5.Lcd.drawString(dots, 35, 85);
        dotCount = (dotCount + 1) % 4;
        animationTimer = millis();
    }
    
    if (IrReceiver.decode()) {
        protocol = IrReceiver.decodedIRData.protocol;
        address = IrReceiver.decodedIRData.address;
        command = IrReceiver.decodedIRData.command;
        rawLength = IrReceiver.decodedIRData.rawDataPtr->rawlen - 1;

        for (uint16_t i = 1; i <= rawLength; i++) {
            rawData[i-1] = IrReceiver.decodedIRData.rawDataPtr->rawbuf[i] * MICROS_PER_TICK;
        }

        M5.Lcd.fillScreen(BLACK);
        drawHeader();
        
        M5.Lcd.fillRoundRect(10, 35, M5.Lcd.width()-20, 80, 8, 0x2104);
        M5.Lcd.drawRoundRect(10, 35, M5.Lcd.width()-20, 80, 8, GREEN);
        
        M5.Lcd.setTextSize(2);
        M5.Lcd.setTextColor(GREEN);
        M5.Lcd.drawString("CAPTURED!", 30, 45);

        M5.Lcd.setTextSize(1);
        M5.Lcd.fillRoundRect(20, 75, M5.Lcd.width()-40, 30, 4, 0x1082);
        M5.Lcd.setTextColor(CYAN);
        M5.Lcd.drawString("CMD: 0x" + String(command, HEX), 30, 85);

        int overlayWidth = 140;
        int overlayHeight = 50;
        int x = (M5.Lcd.width() - overlayWidth) / 2;
        int y = 130;
        
        M5.Lcd.fillRoundRect(x, y, overlayWidth, overlayHeight, 8, 0x4208);
        M5.Lcd.drawRoundRect(x, y, overlayWidth, overlayHeight, 8, currentTheme.primary);
        
        M5.Lcd.setTextSize(2);
        M5.Lcd.fillRoundRect(x+10, y+15, overlayWidth-20, 25, 4, WHITE);
        M5.Lcd.setTextColor(BLACK);
        M5.Lcd.drawString("REPLAY", x+30, y+18);
        
        IrReceiver.resume();
    }
    
    if (M5.BtnA.wasPressed() && rawLength > 0) {
        IrReceiver.stop();

        IrSender.sendRaw(rawData, rawLength, 38);

        M5.Lcd.fillScreen(0x2104);
        delay(100);
        M5.Lcd.fillScreen(BLACK);
        
        IrReceiver.start();
        firstRun = true;
    }
    
    if (M5.BtnPWR.wasPressed()) {
        inIrReplay = false;
        inSubmenu = true;
        firstRun = true;
        displaySubMenu();
    }
}

void displayNetworkList(WiFiScanResult* networks, int count) {
    static int selectedNetwork = 0;
    
    while(true) {
        M5.update();
        
        M5.Lcd.fillScreen(BLACK);
        drawHeader();
        
        for(int i = 0; i < min(5, count); i++) {
            int y = 30 + (i * 25);
            if(i == selectedNetwork) {
                M5.Lcd.fillRoundRect(10, y-2, M5.Lcd.width()-20, 20, 4, WHITE);
                M5.Lcd.setTextColor(BLACK);
            } else {
                M5.Lcd.setTextColor(WHITE);
            }
            M5.Lcd.drawString(networks[i].ssid, 15, y);
        }
        
        if(M5.BtnB.wasPressed()) {
            selectedNetwork = (selectedNetwork + 1) % count;
        }
        
        if(M5.BtnA.wasPressed()) {
            performDeauth(networks + selectedNetwork, 1);
            break;
        }
        
        if(M5.BtnPWR.wasPressed()) {
            inActionOverlay = false;
            displaySubMenu();
            break;
        }
        
        delay(50);
    }
}

void performDeauth(WiFiScanResult* network, int count) {
    for (int i = 0; i < count; i++) {
        Serial.println("Deauthenticating network: " + network[i].ssid);
    }
}

void promiscuousCallback(void* buf, wifi_promiscuous_pkt_type_t type) {
    totalPackets++;
    
    packetHistory[historyIndex] = packetsPerSecond;
    historyIndex = (historyIndex + 1) % PACKET_HISTORY_SIZE;
}

void handleBrandMenu() {
    if (M5.BtnB.wasPressed()) {
        currentSubMenuItem = (currentSubMenuItem + 1) % getMaxSubMenuItems();
        displaySubMenu();
    }
    if (M5.BtnA.wasPressed()) {
        if (currentSubMenuItem == getMaxSubMenuItems() - 1) {
            inBrandMenu = false;
            inIrRemoteMenu = true;
            displaySubMenu();
        } else {
            inActionOverlay = true;
            displayActionOverlay();
        }
    }
}

void handleMainMenu() {
    if (M5.BtnB.wasPressed()) {
        currentMenuItem = (currentMenuItem + 1) % numMenuItems;
        displayMenuItem();
    }
    if (M5.BtnA.wasPressed()) {
        inSubmenu = true;
        currentSubMenuItem = 0;
        displaySubMenu();
    }
}

void handleSubMenu() {
    if (M5.BtnB.wasPressed()) {
        int maxItems = getMaxSubMenuItems() + 1;
        currentSubMenuItem = (currentSubMenuItem + 1) % maxItems;
        displaySubMenu();
    }
    if (M5.BtnA.wasPressed()) {
        handleSubMenuSelection();
    }
}

void handleSubMenuSelection() {
    if (inIrRemoteMenu) {
        if (currentSubMenuItem == getMaxSubMenuItems()) {
            inIrRemoteMenu = false;
            displaySubMenu();
        } else {
            currentDeviceType = currentSubMenuItem;
            inBrandMenu = true;
            currentBrandMenuItem = 0;
            displaySubMenu();
        }
    } else if (currentMenuItem == 1 && currentSubMenuItem == 0) {
        inWiFiScan = true;
        M5.Lcd.fillScreen(BLACK);
    } else if (currentMenuItem == 1 && currentSubMenuItem == 3) {
        inPacketMonitor = true;
        WiFi.mode(WIFI_MODE_STA);
        esp_wifi_set_promiscuous(true);
        esp_wifi_set_channel(currentWiFiChannel, WIFI_SECOND_CHAN_NONE);
        M5.Lcd.fillScreen(BLACK);
    } else if (currentMenuItem == 1 && currentSubMenuItem == 4) {
        inActionOverlay = true;
    } else if (currentMenuItem == 3 && currentSubMenuItem == 0) {
        inRfVisualizer = true;
        M5.Lcd.fillScreen(BLACK);
    } else if (currentMenuItem == 3 && currentSubMenuItem == 1) {
        inRfJammer = true;
        M5.Lcd.fillScreen(BLACK);
    } else if (currentMenuItem == 3 && currentSubMenuItem == 2) {
        if (currentRfModule == 1 || currentRfModule == 2) {
            displayCustomFqOverlay();
        } else if (currentRfModule == 3) {
            M5.Lcd.fillScreen(BLACK);
            drawHeader();
            
            M5.Lcd.setTextSize(2);
            M5.Lcd.setTextColor(YELLOW);
            M5.Lcd.drawString("CC1101 CUSTOM", 20, 50);
            M5.Lcd.drawString("COMING SOON", 30, 80);
            
            delay(1500);
            displaySubMenu();
        } else {
            M5.Lcd.fillScreen(BLACK);
            drawHeader();
            
            M5.Lcd.setTextSize(2);
            M5.Lcd.setTextColor(RED);
            M5.Lcd.drawString("SELECT RF MOD", 20, 60);
            M5.Lcd.setTextSize(1);
            M5.Lcd.drawString("Please select an RF mod first", 10, 90);
            M5.Lcd.drawString("in Configuration > RF Mods", 20, 110);
            
            delay(2000);
            displaySubMenu();
        }
    } else if (currentMenuItem == 4 && currentSubMenuItem == 0) {
        inIrRemoteMenu = true;
        currentSubMenuItem = 0;
        displaySubMenu();
    } else if (currentMenuItem == 4 && currentSubMenuItem == 1) {
        inIrReplay = true;
        M5.Lcd.fillScreen(BLACK);
    } else if (currentMenuItem == 0 && currentSubMenuItem == 6) {
        inBleScanner = true;
        M5.Lcd.fillScreen(BLACK);
    } else if (currentMenuItem == 0 && currentSubMenuItem == 7) {
        inCardSkimmer = true;
        scanning = true;
        currentSkimmer = 0;
        handleCardSkimmer();
    } else if (currentMenuItem == 5 && currentSubMenuItem == 0) {
        handleFileSystem();
    } else if (currentMenuItem == 6 && currentSubMenuItem == 0) {
        displayIrModsOverlay();
    } else if (currentMenuItem == 6 && currentSubMenuItem == 1) {
        displayRfModsOverlay();
    } else if (currentMenuItem == 7 && currentSubMenuItem == 0) {
        inColorSelection = true;
        inSubmenu = false;
        M5.Lcd.fillScreen(BLACK);
        handleColorSelection();
    } else if (currentMenuItem == 7 && currentSubMenuItem == 2) {
        handleCredits();
    } else if (currentSubMenuItem == getMaxSubMenuItems()) {
        inSubmenu = false;
        displayMenuItem();
    }
}

const char* getEncryptionType(wifi_auth_mode_t encType) {
    switch(encType) {
        case WIFI_AUTH_OPEN: return "Open";
        case WIFI_AUTH_WEP: return "WEP";
        case WIFI_AUTH_WPA_PSK: return "WPA";
        case WIFI_AUTH_WPA2_PSK: return "WPA2";
        case WIFI_AUTH_WPA_WPA2_PSK: return "WPA/2";
        case WIFI_AUTH_WPA3_PSK: return "WPA3";
        default: return "Unknown";
    }
}

void displayMenuItem() {
    M5.Lcd.fillScreen(currentTheme.background);
    drawHeader();
    
    int prevItem = (currentMenuItem - 1 + numMenuItems) % numMenuItems;
    int nextItem = (currentMenuItem + 1) % numMenuItems;
    
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(currentTheme.accent);
    M5.Lcd.drawString(menuItems[prevItem], 5, M5.Lcd.height()/2 - 30);
    M5.Lcd.drawString(menuItems[nextItem], M5.Lcd.width() - M5.Lcd.textWidth(menuItems[nextItem]) - 5, M5.Lcd.height()/2 - 30);
    
    M5.Lcd.setTextSize(3);
    M5.Lcd.setTextColor(currentTheme.secondary);
    M5.Lcd.drawString("<", 5, M5.Lcd.height()/2 - 12);
    M5.Lcd.drawString(">", M5.Lcd.width() - 20, M5.Lcd.height()/2 - 12);
    
    M5.Lcd.setTextColor(currentTheme.primary);
    int textWidth = M5.Lcd.textWidth(menuItems[currentMenuItem]);
    int textHeight = M5.Lcd.fontHeight();
    int centerX = (M5.Lcd.width() - textWidth) / 2;
    int centerY = (M5.Lcd.height() - textHeight) / 2;
    
    M5.Lcd.setCursor(centerX, centerY);
    M5.Lcd.print(menuItems[currentMenuItem]);
    
    M5.Lcd.drawLine(centerX, centerY + textHeight + 2, centerX + textWidth, centerY + textHeight + 2, currentTheme.secondary);
    
    drawNavigationDots();
}

void displaySubMenu() {
    M5.Lcd.fillScreen(currentTheme.background);
    drawHeader();
    
    const char** currentSubMenu;
    int maxItems;
    
    if (inBrandMenu) {
        switch(currentDeviceType) {
            case 0: currentSubMenu = tvBrands; maxItems = numTvBrands; break;
            case 1: currentSubMenu = projectorBrands; maxItems = numProjectorBrands; break;
            case 2: currentSubMenu = ledLightBrands; maxItems = numLedLightBrands; break;
            case 3: currentSubMenu = whiteboardBrands; maxItems = numWhiteboardBrands; break;
            case 4: currentSubMenu = touchDisplayBrands; maxItems = numTouchDisplayBrands; break;
            default: return;
        }
    } else if (inIrRemoteMenu) {
        currentSubMenu = irRemoteMenu;
        maxItems = numIrRemoteItems;
    } else {
        switch(currentMenuItem) {
            case 0: currentSubMenu = bluetoothMenu; maxItems = numBluetoothItems; break;
            case 1: currentSubMenu = wifiMenu; maxItems = numWifiItems; break;
            case 2: currentSubMenu = rfidMenu; maxItems = numRfidItems; break;
            case 3: currentSubMenu = rfMenu; maxItems = numRfItems; break;
            case 4: currentSubMenu = irMenu; maxItems = numIrItems; break;
            case 5: currentSubMenu = filesMenu; maxItems = numFilesItems; break;
            case 6: currentSubMenu = configMenu; maxItems = numConfigItems; break;
            case 7: currentSubMenu = settingsMenu; maxItems = numSettingsItems; break;
            default: return;
        }
    }

    const int headerHeight = 25;
    const int screenHeight = M5.Lcd.height() - headerHeight;
    const int itemHeight = 20;
    const int itemPadding = 5;
    const int maxVisibleItems = screenHeight / (itemHeight + itemPadding);

    int adjustedItemSpacing = min(itemSpacing, screenHeight / maxVisibleItems);

    int scrollOffset = 0;
    if (currentSubMenuItem >= maxVisibleItems - 1) {
        scrollOffset = currentSubMenuItem - maxVisibleItems + 2;
    }

    scrollOffset = min(scrollOffset, maxItems + 1 - maxVisibleItems);
    scrollOffset = max(0, scrollOffset);

    int lastVisibleItem = min(scrollOffset + maxVisibleItems, maxItems + 1);

    for (int i = scrollOffset; i < lastVisibleItem; i++) {
        int yPos = headerHeight + ((i - scrollOffset) * adjustedItemSpacing);

        if (i == lastVisibleItem - 1) {
            yPos = min(yPos, M5.Lcd.height() - itemHeight - 5);
        }
        
        M5.Lcd.setTextSize(2);
        
        const char* menuText = (i < maxItems) ? currentSubMenu[i] : "<Back";
        int textWidth = M5.Lcd.textWidth(menuText);
        int x = (M5.Lcd.width() - textWidth) / 2;
        
        if (i == currentSubMenuItem) {
            M5.Lcd.fillRoundRect(x - 5, yPos - 2, textWidth + 10, itemHeight, 8, currentTheme.primary);
            M5.Lcd.setTextColor(currentTheme.background);
        } else {
            M5.Lcd.fillRoundRect(x - 5, yPos - 2, textWidth + 10, itemHeight, 8, currentTheme.accent);
            M5.Lcd.setTextColor(currentTheme.primary);
        }
        M5.Lcd.drawString(menuText, x, yPos);
    }

    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(currentTheme.secondary);
    if (scrollOffset > 0) {
        M5.Lcd.drawString("^", M5.Lcd.width() - 15, headerHeight);
    }
    if (lastVisibleItem < maxItems + 1) {
        M5.Lcd.drawString("v", M5.Lcd.width() - 15, M5.Lcd.height() - 20);
    }
}

void displayActionOverlay() {
    int overlayWidth = 140;
    int overlayHeight = 50;
    int x = (M5.Lcd.width() - overlayWidth) / 2;
    int y = (M5.Lcd.height() - overlayHeight) / 2;
    
    M5.Lcd.fillRoundRect(x, y, overlayWidth, overlayHeight, 8, 0x4208);
    M5.Lcd.drawRoundRect(x, y, overlayWidth, overlayHeight, 8, WHITE);
    
    M5.Lcd.setTextSize(2);
    int textWidth = M5.Lcd.textWidth(brandActions[0]);
    int textX = (M5.Lcd.width() - textWidth) / 2;
    int textY = y + 15;
    
    M5.Lcd.fillRoundRect(textX - 5, textY - 2, textWidth + 10, 20, 8, WHITE);
    M5.Lcd.setTextColor(BLACK);
    M5.Lcd.drawString(brandActions[0], textX, textY);
}

void drawHeader() {
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(currentTheme.primary);
    int titleWidth = M5.Lcd.textWidth("SignalXNetwork V1.0");
    M5.Lcd.drawString("SignalXNetwork V1.0", (M5.Lcd.width() - titleWidth) / 2, 5);
    
    int batPercentage = M5.Power.getBatteryLevel();
    M5.Lcd.drawString(String(batPercentage) + "%", M5.Lcd.width() - 35, 5);
    
    M5.Lcd.drawLine(0, 20, M5.Lcd.width(), 20, currentTheme.accent);
}

void drawNavigationDots() {
    int dotSpacing = 10;
    int dotRadius = 3;
    int totalWidth = (numMenuItems * (dotRadius * 2 + dotSpacing)) - dotSpacing;
    int startX = (M5.Lcd.width() - totalWidth) / 2;
    int y = M5.Lcd.height() - 15;

    for (int i = 0; i < numMenuItems; i++) {
        if (i == currentMenuItem) {
            M5.Lcd.fillCircle(startX + i * (dotRadius * 2 + dotSpacing), y, dotRadius, currentTheme.primary);
        } else {
            M5.Lcd.drawCircle(startX + i * (dotRadius * 2 + dotSpacing), y, dotRadius, currentTheme.accent);
        }
    }
}

int getMaxSubMenuItems() {
    if (inBrandMenu) {
        switch(currentDeviceType) {
            case 0: return numTvBrands;
            case 1: return numProjectorBrands;
            case 2: return numLedLightBrands;
            case 3: return numWhiteboardBrands;
            case 4: return numTouchDisplayBrands;
            default: return 0;
        }
    }
    
    if (inIrRemoteMenu) {
        return numIrRemoteItems;
    }
    
    switch(currentMenuItem) {
        case 0: return numBluetoothItems;
        case 1: return numWifiItems;
        case 2: return numRfidItems;
        case 3: return numRfItems;
        case 4: return numIrItems;
        case 5: return numFilesItems;
        case 6: return numConfigItems;
        case 7: return numSettingsItems;
        default: return 0;
    }
}
void scanSkimmerFrequencies() {
    skimmerCount = 3;
    skimmerDevices = new SkimmerDevice[skimmerCount];
    
    skimmerDevices[0] = {"Skimmer Type 1", "433.92 MHz", -50, "Protocol 1", "Data Rate 1", true};
    skimmerDevices[1] = {"Skimmer Type 2", "315 MHz", -60, "Protocol 2", "Data Rate 2", false};
    skimmerDevices[2] = {"Skimmer Type 3", "868 MHz", -70, "Protocol 3", "Data Rate 3", true};
}

void spamIRCodes(int deviceType, int brandIndex) {
    const int REPEAT_COUNT = 15;
    const int DELAY_MS = 100;
    
    const IRCodes* codes;
    switch(deviceType) {
        case 0: codes = &TV_CODES[brandIndex]; break;
        case 1: codes = &PROJECTOR_CODES[brandIndex]; break;
        case 2: codes = &LED_CODES[brandIndex]; break;
        case 3: codes = &WHITEBOARD_CODES[brandIndex]; break;
        case 4: codes = &TOUCH_DISPLAY_CODES[brandIndex]; break;
        default: return;
    }
    
    for(int i = 0; i < REPEAT_COUNT; i++) {
        M5.update();
        if (M5.BtnPWR.wasPressed()) {
            inActionOverlay = false;
            inBrandMenu = false;
            inIrRemoteMenu = false;
            inSubmenu = false;
            displayMenuItem();
            return;
        }
        
        for(int j = 0; j < 5; j++) {
            IrSender.sendNECMSB(codes->powerOn[j], 32);
            delay(DELAY_MS);

            M5.update();
            if (M5.BtnPWR.wasPressed()) {
                inActionOverlay = false;
                inBrandMenu = false;
                inIrRemoteMenu = false;
                inSubmenu = false;
                displayMenuItem();
                return;
            }
        }
        
        for(int j = 0; j < 5; j++) {
            IrSender.sendNECMSB(codes->powerOff[j], 32);
            delay(DELAY_MS);

            M5.update();
            if (M5.BtnPWR.wasPressed()) {
                inActionOverlay = false;
                inBrandMenu = false;
                inIrRemoteMenu = false;
                inSubmenu = false;
                displayMenuItem();
                return;
            }
        }
    }
}
