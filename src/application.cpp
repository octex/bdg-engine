#include "application.h"

#include <iostream>

void InitApplication()
{
    LoadSettings();
    int screenWidth = settings[SCREEN_WIDTH];
    int screenHeight = settings[SCREEN_HEIGHT];
    InitWindow(screenWidth, screenHeight, APPLICATION_NAME);
    SetTargetFPS(TARGET_FPS);
    InitThings(currentScene);
}

void Update()
{
    // Update cycle here
    UpdateThings(currentScene);
}

void Render()
{
    BeginDrawing();
        RenderThings(currentScene);
        ClearBackground(BLACK);
    EndDrawing();
}

void CloseApplication()
{
    // Application closing routine
    CloseWindow();
}