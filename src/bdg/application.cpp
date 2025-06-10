#include "application.h"

#include <iostream>

Scene *currentScene;
Camera2D appCamera;
Thing *gamePlayer;
float deltaTime;

void InitApplication()
{
    LoadSettings();
    int screenWidth = settings.screenWidth;
    int screenHeight = settings.screenHeight;
    InitWindow(screenWidth, screenHeight, APPLICATION_NAME);
    SetTargetFPS(TARGET_FPS);
    if (settings.fullscreen)
    {
        ToggleFullscreen();
    }
    LoadAssets();
    appCamera = {0};
    appCamera.offset = Vector2{screenWidth/2.0f, screenHeight/2.0f };
    appCamera.zoom = 1;
    appCamera.rotation = 0;
    if (!currentScene)
    {
        currentScene = LoadScene(assets[START_SCENE]);
    }
    InitScene(currentScene);
}

void Update()
{
    // Update cycle here
    deltaTime = GetFrameTime();
    UpdateScene(currentScene);
}

void Render()
{
    BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(0, 0);
        BeginMode2D(appCamera);
            DrawAxis();
            RenderScene(currentScene);
        EndMode2D();
    EndDrawing();
}

void CloseApplication()
{
    // Application closing routine
    UnloadScene(currentScene);
    MemFree(currentScene);
    CloseWindow();
}

void DrawAxis()
{
    if (DEVELOPER_MODE)
    {
        DrawLine(0, 0, 100, 0, BLUE);   // X axis
        DrawLine(0, 0, 0, 100, RED);    // Y axis
        DrawText("(0, 0)", 0, 0, 10, WHITE);
    }
}