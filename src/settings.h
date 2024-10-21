#ifndef SETTINGS_H
#define SETTINGS_H

#include <fstream>
#include <string>
#include <map>

#define SETTINGS_FILENAME "settings.cnf"

#define SCREEN_WIDTH "screen_width"
#define SCREEN_HEIGHT "screen_height"

extern std::map<std::string, int> settings;

typedef struct SettingsData
{
    const char * key;
    int data;
} SettingsData;


void LoadSettings();
int GetSetting(std::string key);

#endif