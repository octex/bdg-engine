#include "application.h"
int main(void)
{
    // Initialization
    Scene *scene = (Scene*)MemAlloc(sizeof(Scene));
    scene->things.push_back(Thing{0, {0, 0}, STATIC, {10}, MemAlloc(sizeof(StaticObj))});
    scene->things.push_back(Thing{1, {100, 20}, STATIC, {11}, MemAlloc(sizeof(StaticObj))});
    currentScene = scene;

    InitApplication();
    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        Update();
        // Render
        Render();
    }
    CloseApplication();

    return 0;
}