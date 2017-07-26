#include "Splash_Screen.h"

#include "Globals.h"
#include "Main_Menu.h"

USING_NS_CC;

Scene* Splash_Screen::createScene()
{
    return Splash_Screen::create();
}

// on "init" you need to initialize your instance
bool Splash_Screen::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto splashScreenBg = Sprite::create("bird1.png");
    splashScreenBg->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
   splashScreenBg->setScale(2,2);
    this->addChild(splashScreenBg);

this->scheduleOnce(schedule_selector(Splash_Screen::GotoMainMenu), SPLASH_SCREEN_DURATION );



	
    return true;
}

void Splash_Screen::GotoMainMenu(float d)
{
auto menuScene= Main_Menu::createScene();
Director::getInstance()->replaceScene(TransitionFade::create(1,menuScene) );


}

