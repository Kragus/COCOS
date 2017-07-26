
#ifndef PROJ_ANDROID_STUDIO_OBSTACLES_H
#define PROJ_ANDROID_STUDIO_OBSTACLES_H

#include "cocos2d.h"

class Obstacles: public cocos2d::Layer
{
public:
    Obstacles();

 void spawnObstacles(cocos2d::Layer * spawnLayer);

    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Sprite* top;
    cocos2d::Sprite* bottom;
    cocos2d::Node *center;
    float obsVelocity;
    void declareDead(float d);



};

#endif //PROJ_ANDROID_STUDIO_OBSTACLES_H
