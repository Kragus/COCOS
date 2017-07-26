
#include "SimpleAudioEngine.h"
#include "Main_Menu.h"
#include "MainGameScene.h"

USING_NS_CC;

Scene*  Main_Menu::createScene()
{   auto scene = Scene::createWithPhysics();
    auto layer = Main_Menu::create();

    scene->addChild(layer);

    return  scene;


}

// on "init" you need to initialize your instance
bool  Main_Menu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundImg = Sprite::create("main_background.png");
    backgroundImg->setScale(visibleSize.width/backgroundImg->getContentSize().width,visibleSize.height/backgroundImg->getContentSize().height);
    backgroundImg->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
    this->addChild(backgroundImg);

    auto titleSprite = Sprite::create("game_name.png");
    titleSprite->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/1.5));
    titleSprite->setScale(2);
    this->addChild(titleSprite);

    MenuItemImage * playButton;
    playButton = MenuItemImage::create("play_button.png","play_button_clicked.png", CC_CALLBACK_1(Main_Menu::StartGame, this ));
    playButton->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height*0.3));
    playButton->setScale(2);
    Menu * mainMenu = Menu::create(playButton,NULL);
    mainMenu->setPosition(Point::ZERO);
    this->addChild(mainMenu);

    _road= Road((Layer*) this);
    Bird = Flappy((Layer*) this);
    Bird.FlappySprite->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));

    this->scheduleUpdate();
    return true;






}

void Main_Menu::StartGame(cocos2d::Ref *sender)
{
    auto gameScene= MainGameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1,gameScene) );

}
void Main_Menu::update(float d){

_road.rollRoad();


}