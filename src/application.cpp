#include "application.h"

#include <iostream>

Scene *currentScene;

void InitApplication()
{
    LoadSettings();
    int screenWidth = settings[SCREEN_WIDTH];
    int screenHeight = settings[SCREEN_HEIGHT];
    InitWindow(screenWidth, screenHeight, APPLICATION_NAME);
    SetTargetFPS(TARGET_FPS);
    LoadAssets();
    InitScene(currentScene);
}

void Update()
{
    // Update cycle here
    UpdateScene(currentScene);
}

void Render()
{
    BeginDrawing();
        ClearBackground(BLACK);
        RenderScene(currentScene);
    EndDrawing();
}

void CloseApplication()
{
    // Application closing routine
    UnloadScene(currentScene);
    MemFree(currentScene);
    CloseWindow();
}