#include "things.h"

void InitAnimator(Thing* thing, ThingAnimator* animator)
{
    animator = (ThingAnimator*)MemAlloc(sizeof(ThingAnimator));
    animator->animations = {};
    animator->currentAnimation = {};
    animator->stateMachine = {};
    char* animatorFileContent = LoadFileText(assets[GetThingAttr(thing, ATTR_ANIMATOR)]);
    UnloadFileText(animatorFileContent);
}

void SetAndPlayAnimation(ThingAnimator* animator, std::string animationId)
{
    ThingAnimation *animToPlay = animator->animations[animationId];
    if (!animToPlay)
    {
        return;
    }
    else if (animator->currentAnimation != animToPlay)
    {
        animator->currentAnimation->state = READY;
        animator->currentAnimation->frame = 0;
        animator->currentAnimation = animToPlay;
        animator->currentAnimation->state = PLAYING;
    }
    else if (animator->currentAnimation == animToPlay && animator->currentAnimation->state != PLAYING)
    {
        animator->currentAnimation->state = PLAYING;
    }
}