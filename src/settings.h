#ifndef SETTINGS_H
#define SETTINGS_H

#include <raylib.h>
#include <fstream>
#include <string>
#include <string.h>
#include <map>

#define SETTINGS_FILENAME "settings.cnf"

#define SCREEN_WIDTH "scrw"
#define SCREEN_HEIGHT "scrh"
#define MUSIC_VOLUME "mvol"
#define SFX_VOLUME "svol"

extern std::map<std::string, int> settings;

// ***  List of common keywords for settings ***
// screen_width:    scrw
// screen_height:   scrh
// music_volume:    mvol
// sfx_volume:      svol

typedef struct SettingsData
{
    char key[5];
    int data;
} SettingsData;


void LoadSettings();
int GetSetting(std::string key);

#endif