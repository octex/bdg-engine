#include "things.h"

void UpdateStatus(ThingAnimation* animation, ThingAnimationState newState)
{
    animation->state = newState;
    if (newState == READY)
    {
        animation->frame = 0;
    }
}

void PlayAnimation(ThingAnimation* animation)
{

}

void PauseAnimation(ThingAnimation*)
{

}

void StopAnimation(ThingAnimation*)
{

}

void RenderAnimation(ThingAnimation* animation)
{

}