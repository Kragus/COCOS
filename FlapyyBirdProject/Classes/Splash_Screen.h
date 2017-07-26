#ifndef __SPLASH_SCREEN_H__
#define __SPLASH_SCREEN_H__

#include "cocos2d.h"

class Splash_Screen: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void GotoMainMenu(float d);
	
    // implement the "static create()" method manually
    CREATE_FUNC(Splash_Screen);
};

#endif // __SPLASH_SCREEN_H__
