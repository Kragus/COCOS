#include "Obstacles.h"
#include "Globals.h"

USING_NS_CC;

Obstacles::Obstacles()
{

Obstacles::visibleSize = Director::getInstance()->getVisibleSize();
Obstacles::origin= Director::getInstance()->getVisibleOrigin();

}


void Obstacles::spawnObstacles(cocos2d::Layer *spawnLayer)
{
   top = Sprite::create("pipe.png");
    bottom = Sprite::create("pipe.png");

    top->setAnchorPoint(Vec2(0.5,0));
    bottom->setAnchorPoint(Vec2(0.5,1));
    top->setTextureRect(Rect(0,0,top->getContentSize().width,visibleSize.height));
    bottom->setTextureRect(Rect(0,0,bottom->getContentSize().width,visibleSize.height));
    top->setScale(2);
    bottom->setScale(2);
    top->setFlippedY(true);
    center = Node::create( );

    top->setTag(10);
    bottom->setTag(10);

    auto topPhysics = PhysicsBody::createBox(top->getContentSize());
    auto botPhysics = PhysicsBody::createBox(bottom->getContentSize());


    topPhysics->setDynamic(false);
    botPhysics->setDynamic(false);


    topPhysics->setCollisionBitmask(OBSTACLE_COLISION_BITID);
    topPhysics->setContactTestBitmask(true);

    botPhysics->setCollisionBitmask(OBSTACLE_COLISION_BITID);
   botPhysics->setContactTestBitmask(true);




    float rand = random(0.10,0.50);

    top->setPosition(origin.x+visibleSize.width+top->getContentSize().width,(origin.y+ visibleSize.height- (visibleSize.height*rand)));
    bottom->setPosition(top->getPosition().x,top->getPosition().y-(visibleSize.height/5));


    auto centerPhysics = PhysicsBody::createBox(Size(1,abs(top->getPosition().y-bottom->getPosition().y)));
    centerPhysics->setCollisionBitmask(POINT_COLLISION_BITID);
    centerPhysics->setContactTestBitmask(true);
    centerPhysics->setDynamic(false);
    center->setAnchorPoint(Vec2(0.5,1));
    center->setPosition( Vec2(top->getPosition().x,top->getPosition().y-(abs(top->getPosition().y-bottom->getPosition().y)/2)));


    top->setPhysicsBody(topPhysics);
    bottom->setPhysicsBody(botPhysics);
    center->setPhysicsBody(centerPhysics);

    spawnLayer->addChild(top);
    spawnLayer->addChild(bottom);
    spawnLayer->addChild(center);
    obsVelocity = LINEAR_VELOCITY;

    topPhysics->setVelocity(Vec2(obsVelocity,0));
    botPhysics->setVelocity(Vec2(obsVelocity,0));
    centerPhysics->setVelocity(Vec2(obsVelocity,0));

    this->scheduleOnce(schedule_selector(Obstacles::declareDead),10);





}

void Obstacles::declareDead(float d){
top->removeFromParent();
    bottom->removeFromParent();
    top->autorelease();
    bottom->autorelease();
   center->removeFromParent();
    center->autorelease();

}