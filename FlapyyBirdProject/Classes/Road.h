
#ifndef __ROAD_H__
#define __ROAD_H__

#include "cocos2d.h"

class Road
{
public:
    Road()
    {};

    Road(cocos2d::Layer * spawnLayer);
    void callBackFunction();
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    void rollRoad();
    cocos2d::Sprite* road1;
    cocos2d::Sprite* road2;
    cocos2d::Sprite* road3;
    float road_velocity;






};

#endif //__ROAD_H__
