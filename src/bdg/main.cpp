#include "application.h"

int main(void)
{
    // Initialization
    Scene *scene = (Scene*)MemAlloc(sizeof(Scene));

    Thing box1 = Thing{0, {130, 266}, STATIC, {4}, true, NULL, NULL};
    Thing box2 = Thing{0, {130, 394}, STATIC, {4}, true, NULL, NULL};
    // Thing box2 = Thing{0, {2, 266}, STATIC, {4}, true, NULL, NULL};

    AddThing(scene, &box1);
    AddThing(scene, &box2);

    // scene->things.push_back(Thing{0, {0, 0}, STATIC, {10}});
    ThingAttr<int> playerIntAttrs;
    playerIntAttrs.attrs["sprite_asset_id"] = 3;
    Thing player = Thing{0, Vector2Zero(), PLAYER, {3}, true, NULL, NULL, playerIntAttrs, {}};
    AddThing(scene, &player);

    TileSet *tileSet = (TileSet*)MemAlloc(sizeof(TileSet));
    tileSet->tileHeight = 32;
    tileSet->tileWidth = 32;
    Thing tileSetThing = Thing{0, {0, 0}, TILESET, {1}, false, tileSet, NULL};

    AddThing(scene, &tileSetThing);

    
    TileMap *tileMap = (TileMap*)MemAlloc(sizeof(TileMap));
    tileMap->xCell = 32;
    tileMap->yCell = 32;

    tileMap->tiles.push_back(Tile{{0, 0}, 1, tileSet});

    for (int i = 1; i < 10; i++)
    {
        tileMap->tiles.push_back(Tile{{(float)i, 0}, i + 1, tileSet});
        tileMap->tiles.push_back(Tile{{0, (float)i}, i + 1, tileSet});
    }

    Thing tileMapThing = Thing{1, {250, 250}, TILEMAP, {}, false, tileMap};

    scene->things.push_back(&tileMapThing);








    currentScene = scene;
    gamePlayer = &player;

    InitApplication();
    // Main game loop
    while (!WindowShouldClose())
    {
        Update();
        Render();
    }
    CloseApplication();
    return 0;
}