#ifndef SCENES_H
#define SCENES_H

#include <raylib.h>
#include <vector>
#include "things.h"


typedef struct Scene
{
    // std::vector <Asset*> assets; -> Missing files
    std::vector<Thing*> things;
} Scene;


#endif