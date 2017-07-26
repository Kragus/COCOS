#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "cocos2d.h"
#include "Road.h"
#include "Flappy.h"
class Main_Menu: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

public:
    void StartGame(cocos2d::Ref *sender);
	Road _road;
	Flappy Bird;
    void update(float d);
    // implement the "static create()" method manually
    CREATE_FUNC( Main_Menu);


};

#endif //__MAIN_MENU_H__
