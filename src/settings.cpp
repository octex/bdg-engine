#include "settings.h"

std::map<std::string, int> settings;

#include <iostream>

void LoadSettings()
{
    bool settingsFileExists = FileExists(SETTINGS_FILENAME);
    if (!settingsFileExists)
    {
        FILE *newSettingsFile = fopen(SETTINGS_FILENAME, "wb");
        int amount = 2;
        char keys[2][5] = {SCREEN_WIDTH, SCREEN_HEIGHT};
        int values[] = {1024, 728};
        for (int i = 0; i < amount; i++)
        {
            SettingsData settingsData = {};
            strcpy(settingsData.key, keys[i]);
            settingsData.data = values[i];
            settings.insert({settingsData.key, settingsData.data});
            fwrite(&settingsData, sizeof(SettingsData), 1, newSettingsFile);
        }
        fclose(newSettingsFile);
    }
    else
    {
        FILE *settingsFile = fopen(SETTINGS_FILENAME, "rb");
        SettingsData settingsDataR = {};
        fread(&settingsDataR, sizeof(SettingsData), 1, settingsFile);
        settings.insert({settingsDataR.key, settingsDataR.data});
        while (!feof(settingsFile))
        {
            fread(&settingsDataR, sizeof(SettingsData), 1, settingsFile);
            settings.insert({settingsDataR.key, settingsDataR.data});
        }
        fclose(settingsFile);
    }
}

int GetSetting(std::string key)
{
    return settings[key];
}