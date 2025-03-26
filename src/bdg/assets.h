#ifndef TBOX_ASSETS
#define TBOX_ASSETS

#include <map>
#include <string>
#include <stdlib.h>
#include "raylib.h"

#define ASSETS_DIR "resources/"

typedef struct Asset
{
    int id;
    const char *dir;
} Asset;

extern std::map<std::string, const char *> assets;
extern FilePathList assetsDirs;

void LoadAssetsDirs();
void LoadAssets();

#endif