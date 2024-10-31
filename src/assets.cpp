#include "assets.h"

std::map<int, Asset> assets;
FilePathList assetsDirs;


void LoadAssets()
{
    LoadAssetsDirs();
    for (int i = 0; i < assetsDirs.count; i++)
    {
        const char *path = assetsDirs.paths[i];
        const char *filename = GetFileName(path);
        const char *fileNameWithoutExt = GetFileNameWithoutExt(path);
        const char *fileExtension = GetFileExtension(filename);
        int assetId = atoi(fileNameWithoutExt);
        Asset newAsset = {};
        newAsset.id = assetId;
        newAsset.dir = path;
        assets.insert(std::pair<int, Asset>(assetId, newAsset));
        // newAsset.assetType = GetAssetTypeByFileExtension(fileExtension);
    }
}

void LoadAssetsDirs()
{
    bool resExists = DirectoryExists(ASSETS_DIR);
    if (!resExists)
    {
        exit(-1);
    }
    assetsDirs = LoadDirectoryFiles(ASSETS_DIR);
}

// AssetType GetAssetTypeByFileExtension(const char* fileExtension)
// {
//     if (fileExtension == ".png") {
//         return TEXTURE;
//     }
// }

// Asset* LoadAsset(const char* filename, AssetType assetType)
// {
//     Asset *asset = (Asset*) malloc(sizeof(Asset));
//     switch (assetType)
//     {
//     case TEXTURE:
//         Texture texture = LoadTexture(filename);
//         asset->asset = (Texture*)asset->asset;
//         asset->asset = &texture;
//         break;
//     default:
//         break;
//     }
// }
