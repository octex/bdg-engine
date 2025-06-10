#ifndef SETTINGS_H
#define SETTINGS_H

#include <raylib.h>
#include <string>
#include <string.h>
#include "toml.hpp"

#define SETTINGS_FILENAME "settings.toml"
#define DEFAULT_WIN_HEIGHT 768
#define DEFAULT_WIN_WIDTH 1024
#define DEFAULT_WIN_FULLSCREEN true

/*  FLAGS   */
#define DEVELOPER_MODE true

using namespace std::literals;

typedef struct ApplicationSettings
{
    int screenWidth, screenHeight;
    bool fullscreen;
    float musicVol, soundVol;
} ApplicationSettings;

extern ApplicationSettings settings;

void LoadSettings();
void UpdateSettings();

#endif
