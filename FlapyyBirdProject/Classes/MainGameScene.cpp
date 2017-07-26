#include "MainGameScene.h"

#include "MainGameScene.h"

#include "Globals.h"

USING_NS_CC;


Scene*  MainGameScene::createScene()
{   auto scene = Scene::createWithPhysics();
   // scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = MainGameScene::create();

    scene->addChild(layer);

    return  scene;


}
// on "init" you need to initialize your instance
bool  MainGameScene::init()
{


    if ( !Scene::init() )
    {
        return false;
    }

     visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
	
	  auto backgroundImg = Sprite::create("main_background.png");
    backgroundImg->setScale(visibleSize.width/backgroundImg->getContentSize().width,visibleSize.height/backgroundImg->getContentSize().height);
    backgroundImg->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
  this->addChild(backgroundImg);


    instructionSprite = Node::create();
    instructionSprite->setContentSize(visibleSize);
    auto tapTapSprite = Sprite::create("tap_tap.png");
    auto getReadySprite = Sprite::create("get_ready.png");

    getReadySprite->setPosition(Vec2(getReadySprite->getPosition().x,instructionSprite->getContentSize().height*0.2));
    instructionSprite->addChild(tapTapSprite);
    instructionSprite->addChild(getReadySprite);


    this->addChild(instructionSprite,5);
    instructionSprite->setPosition(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2);





    score=0;
    scoreText = Label::createWithTTF(StringUtils::format("%02d",score),"Minecrafter_3.ttf", 20,Size::ZERO,TextHAlignment::CENTER);
    scoreText->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+ visibleSize.height*0.8));
    this->addChild(scoreText);





     Bird = Flappy((Layer*) this);
    fly=false;
    gravity = CUSTOM_GRAVITY;
    fly=false;
    upVelocity=UP_VELOCITY;
    downVelocity=0;
    this->scheduleUpdate();

    gameover=false;
    gameRunning=false;

    auto touchlistner = EventListenerTouchOneByOne::create();
//touchlistner->setSwallowTouches(true);
    touchlistner->onTouchBegan = CC_CALLBACK_2(MainGameScene::onTouchBegan,this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchlistner, this);



    _road= Road((Layer*) this);


    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(MainGameScene::onContactBegin,this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener,this);

    return true;


}


bool MainGameScene::onTouchBegan(cocos2d::Touch *, cocos2d::Event *){


   if(gameRunning&&(Bird.FlappySprite->getPosition().y<origin.y+visibleSize.height-10 )) {
       fly = true;
       upVelocity = UP_VELOCITY;
       downVelocity = 0;
   }

   else

   {   Bird._stopHoverAction();
       this->removeChild(instructionSprite);
       gameRunning=true;
       fly = true;
       upVelocity = UP_VELOCITY;
       downVelocity = 0;
       this->schedule(schedule_selector(MainGameScene::spawnPipes),2);

   }
}
void MainGameScene::spawnPipes(float d)
{

    Obs.spawnObstacles((Layer *) this);


}

bool MainGameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
    PhysicsBody *firstBody = contact.getShapeA()->getBody();
    PhysicsBody *secondBody = contact.getShapeB()->getBody();
    if((firstBody->getCollisionBitmask()==BIRD_COLSION_BITID && secondBody->getCollisionBitmask()==POINT_COLLISION_BITID )||(secondBody->getCollisionBitmask()==BIRD_COLSION_BITID && firstBody->getCollisionBitmask()==POINT_COLLISION_BITID ))
    {
       incrimentScore();
    }
    else if((firstBody->getCollisionBitmask()==BIRD_COLSION_BITID && secondBody->getCollisionBitmask()==OBSTACLE_COLISION_BITID )||(secondBody->getCollisionBitmask()==BIRD_COLSION_BITID && firstBody->getCollisionBitmask()==OBSTACLE_COLISION_BITID ))
    {   gameover=true;
        gameRunning=false;
        _road.road_velocity=0;
        auto userDefault = cocos2d::UserDefault::getInstance();
        if(userDefault->getIntegerForKey("highestScore")!=NULL)
        {
            if(userDefault->getIntegerForKey("highestScore")<score)
            {
                userDefault->setIntegerForKey("highestScore",score);
            }
        } else
        {
            userDefault->setIntegerForKey("highestScore",score);
        }
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();


        Gmenu.spawnMenu((Layer*)this,score);
        this->unschedule(schedule_selector(MainGameScene::spawnPipes));
        for(int i=0;i< this->getChildrenCount();i++)
        {
            auto check  = this->getChildren( ).at(i);
            if(check->getTag()==10)
            {
                check->getPhysicsBody()->setVelocity(Vec2(0,0));
            }


        }

    }


}
void MainGameScene::update(float d)
{

    _road.rollRoad();
if(gameRunning) {



    if (!fly) {
        Bird.FlappySprite->setPosition(Vec2(Bird.FlappySprite->getPosition().x,
                                            Bird.FlappySprite->getPosition().y -
                                            (downVelocity *d*3)));
        downVelocity += gravity;
        if (Bird.FlappySprite->getRotation() < 60) {
            Bird.FlappySprite->setRotation(Bird.FlappySprite->getRotation() + exp2(powf(2,downVelocity/100)) );
        }
    } else {
        if (Bird.FlappySprite->getRotation() > -60) {
            Bird.FlappySprite->setRotation(Bird.FlappySprite->getRotation() - 10);
        }
        Bird.FlappySprite->setPosition(Vec2(Bird.FlappySprite->getPosition().x,
                                            Bird.FlappySprite->getPosition().y +
                                            (upVelocity*d*2 )));
        upVelocity -= gravity * 2.5;
        if (upVelocity <= 0) {
            fly = false;
        }
    }
}

    if(gameover)
    {

            Bird.FlappySprite->setPosition(Vec2(Bird.FlappySprite->getPosition().x,
                                                Bird.FlappySprite->getPosition().y -
                                                (downVelocity * d * 3)));
            downVelocity += gravity;
    }

}
void MainGameScene::incrimentScore()
{score++;
    scoreText->setString(StringUtils::toString(score));
}