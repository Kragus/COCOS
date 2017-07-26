
#ifndef __FLAPPY_H__
#define __FLAPPY_H__

#include "cocos2d.h"

class Flappy
{
public:
    Flappy()
    {

    }
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;


    Flappy(cocos2d::Layer *spawnLayer);

    void _stopHoverAction();
    cocos2d::Sprite* FlappySprite;
    cocos2d::Sequence* hoverSequence;
};



#endif //__FLAPPY_H__
