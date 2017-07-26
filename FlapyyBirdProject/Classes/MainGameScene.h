#ifndef __MAIN_GAME_SCENE_H__
#define __MAIN_GAME_SCENE_H__
#include "Flappy.h"
#include "cocos2d.h"
#include "Obstacles.h"
#include "Road.h"
#include "GameOver.h"
class MainGameScene: public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
	void spawnPipes(float d);
    // implement the "static create()" method manually
    CREATE_FUNC( MainGameScene);
    Obstacles Obs;
    bool fly;
    float upVelocity;
    float downVelocity;
    float gravity;
    void update(float d);
    Road _road;
    GameOver Gmenu;
    bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    bool gameover;
    bool gameRunning;
    int score;
    cocos2d::Label* scoreText;
    Flappy Bird;
    Node* instructionSprite;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
	void incrimentScore();



};

#endif //__MAIN_GAME_SCENE_H__