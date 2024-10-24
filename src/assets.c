#include "assets.h"

Asset* assets[BASE_ASSETS_SIZE_ARR];
int amountOfAssets;

void LoadBaseAssets()
{
    amountOfAssets = BASE_ASSETS_SIZE_ARR;
    FilePathList path = LoadDirectoryFiles("./resources");
    for (int i = 0; i < BASE_ASSETS_SIZE_ARR; i++)
    {
        const char* filename = path.paths[i];
        assets[i] = LoadAsset(filename, GetAssetTypeByFileExtension(
            GetFileExtension(filename)
        ));
    }
}

void UnloadBaseAssets()
{
    for (int i = 0; i < BASE_ASSETS_SIZE_ARR; i++)
    {
        free(assets[i]->asset);
        free(assets[i]);
    }
}

AssetType GetAssetTypeByFileExtension(const char* fileExtension)
{
    if (fileExtension == ".png") {
        return TEXTURE;
    }
}

Asset* LoadAsset(const char* filename, AssetType assetType)
{
    Asset *asset = (Asset*) malloc(sizeof(Asset));
    switch (assetType)
    {
    case TEXTURE:
        Texture texture = LoadTexture(filename);
        asset->asset = (Texture*)asset->asset;
        asset->asset = &texture;
        break;
    
    default:
        break;
    }
}

Asset GetAsset(int assetId)
{
    return *(assets[assetId]);
}
