#include "filesystem.h"

bool initFileSystem() {
    return SPIFFS.begin(true);
}

bool fileExists(const char* path) {
    return SPIFFS.exists(path);
}

String readFile(const char* path) {
    if (!fileExists(path)) {
        return "";
    }
    
    File file = SPIFFS.open(path, "r");
    if (!file) {
        return "";
    }
    
    String content = file.readString();
    file.close();
    return content;
}

bool writeFile(const char* path, const String& content) {
    File file = SPIFFS.open(path, "w");
    if (!file) {
        return false;
    }
    
    bool success = file.print(content);
    file.close();
    return success;
}

bool deleteFile(const char* path) {
    if (!fileExists(path)) {
        return true;
    }
    
    return SPIFFS.remove(path);
}
