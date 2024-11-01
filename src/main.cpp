#include "application.h"
int main(void)
{
    // Initialization
    Scene *scene = (Scene*)MemAlloc(sizeof(Scene));
    
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