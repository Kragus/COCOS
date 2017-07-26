#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "cocos2d.h"

class GameOver: public cocos2d::Layer
{
public:
    GameOver(){

    }
    void spawnMenu(cocos2d::Layer *spawnLayer,int currentScore);

    void RestartGame(cocos2d::Ref *sender);



    // implement the "static create()" method manually



};

#endif //__GAME_OVER_H__
