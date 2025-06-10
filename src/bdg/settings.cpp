#include "settings.h"

ApplicationSettings settings;

#include <iostream>

void LoadSettings()
{
    if (!FileExists(SETTINGS_FILENAME))
    {
        std::string baseSettings = "[screen]\nheight = " + std::to_string(DEFAULT_WIN_HEIGHT) + "\nwidth = " + std::to_string(DEFAULT_WIN_WIDTH) + "\nfullscreen = true";
        SaveFileText(SETTINGS_FILENAME, (char *)baseSettings.c_str());
    }
    auto config = toml::parse_file(SETTINGS_FILENAME);
    settings = {};
    settings.fullscreen = config["screen"]["fullscreen"].value_or(DEFAULT_WIN_FULLSCREEN);
    settings.screenHeight = config["screen"]["height"].value_or(DEFAULT_WIN_HEIGHT);
    settings.screenWidth = config["screen"]["width"].value_or(DEFAULT_WIN_WIDTH);
}
