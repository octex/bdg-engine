#include "assets.h"

#include <iostream>

std::map<int, Asset> _assets;
std::map<std::string, const char *> assets;
FilePathList assetsDirs;


void LoadAssets()
{
    LoadAssetsDirs();
    for (int i = 0; i < assetsDirs.count; i++)
    {
        const char *path = assetsDirs.paths[i];
        const char *filename = GetFileName(path);
        assets.insert(std::pair<std::string, const char *>(filename, path));
    }
}

void LoadAssetsDirs()
{
    bool resExists = DirectoryExists(ASSETS_DIR);
    if (!resExists)
    {
        exit(-1);
    }
    assetsDirs = LoadDirectoryFilesEx(ASSETS_DIR, NULL, true);
}
