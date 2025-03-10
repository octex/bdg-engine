#include "things.h"

void InitAnimator(ThingAnimator* animator, int animationId)
{

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