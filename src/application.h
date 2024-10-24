#ifndef BDG_APPLICATION_H
#define BDG_APPLICATION_H

#include <raylib.h>
#include "settings.h"
#include "scenes.h"

#define APPLICATION_NAME "BDG"
#define TARGET_FPS 60

Scene *currentScene;

void InitApplication();
void Update();
void Render();
void CloseApplication();

#endif