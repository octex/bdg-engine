#include "things.h"

void InitAnimator(ThingAnimator* animator)
{
    animator = (ThingAnimator*)MemAlloc(sizeof(ThingAnimator));
}

void SetAndPlayAnimation(ThingAnimator* animator, int animationId)
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