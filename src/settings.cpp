#include "settings.h"

std::map<std::string, int> settings;

#include <iostream>

void LoadSettings()
{
    FILE *settingsFile = fopen(SETTINGS_FILENAME, "rb");
    if (settingsFile == NULL)
    {
        FILE *newSettingsFile = fopen(SETTINGS_FILENAME, "wb");
        SettingsData settingsData;
        int amount = 2;
        const char* keys[] = {"screen_width", "screen_height"};
        int values[] = {800, 450};
        for (int i = 0; i < amount; i++)
        {
            settingsData.key = keys[i];
            settingsData.data = values[i];
            settings.insert({settingsData.key, settingsData.data});
            fwrite(&settingsData, sizeof(settingsData), 1, newSettingsFile);
        }
        fclose(newSettingsFile);
    }
    else
    {
        SettingsData settingsDataR;
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