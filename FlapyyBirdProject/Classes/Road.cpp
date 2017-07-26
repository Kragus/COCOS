#include "Road.h"
#include "Globals.h"



USING_NS_CC;



Road::Road(cocos2d::Layer *spawnLayer)
{visibleSize = Director::getInstance()->getVisibleSize();
    origin= Director::getInstance()->getVisibleOrigin();
    road1 = Sprite::create("road_base.png");
    road2= Sprite::create("road_base.png");
    road3 = Sprite::create("road_base.png");


    road1->setAnchorPoint(Vec2(0,0));
    road2->setAnchorPoint(Vec2(0,0));
    road3->setAnchorPoint(Vec2(0,0));

    road1->setScale(2);
    road2->setScale(2);
    road3->setScale(2);

    auto road1Physics = PhysicsBody::createBox(road1->getContentSize());
    auto road2Physics = PhysicsBody::createBox(road2->getContentSize());
    auto road3Physics = PhysicsBody::createBox(road3->getContentSize());



   road1Physics->setCollisionBitmask(OBSTACLE_COLISION_BITID);
    road1Physics->setContactTestBitmask(true);
    road2Physics->setCollisionBitmask(OBSTACLE_COLISION_BITID);
    road2Physics->setContactTestBitmask(true);
    road3Physics->setCollisionBitmask(OBSTACLE_COLISION_BITID);
    road3Physics->setContactTestBitmask(true);

    road1Physics->setDynamic(false);
    road2Physics->setDynamic(false);
    road3Physics->setDynamic(false);

    road1->setPhysicsBody(road1Physics);
    road2->setPhysicsBody(road2Physics);
    road3->setPhysicsBody(road3Physics);





    road1->setPosition(Point(0,0));
    road2->setPosition(Vec2(road1->getPosition().x+road1->getContentSize().width*2,road1->getPosition().y));
    road3->setPosition(Vec2(road2->getPosition().x+road2->getContentSize().width*2,road2->getPosition().y));

    spawnLayer->addChild(road1,1);
    spawnLayer->addChild(road2,1);
    spawnLayer->addChild(road3,1);


    road_velocity=LINEAR_VELOCITY;








}
void Road::callBackFunction()
{

}


 void Road::rollRoad()
{
     /*road1->setPosition(Vec2(road1->getPosition().x-(1),road1->getPosition().y));
    road2->setPosition(Vec2(road2->getPosition().x-(1),road2->getPosition().y));
    road3->setPosition(Vec2(road3->getPosition().x-(1),road3->getPosition().y));
*/


    road1->getPhysicsBody()->setVelocity(Vec2(road_velocity,0));
    road2->getPhysicsBody()->setVelocity(Vec2(road_velocity,0));
    road3->getPhysicsBody()->setVelocity(Vec2(road_velocity,0));

    if(road1->getPosition().x<=-(road1->getContentSize().width))
    {
        road1->setPosition(Vec2((road3->getPosition().x)+(road3->getContentSize().width*2),road3->getPosition().y));

    }
    if(road2->getPosition().x<=-(road2->getContentSize().width))
    {
        road2->setPosition(Vec2((road1->getPosition().x)+(road1->getContentSize().width*2),road1->getPosition().y));

    }
    if(road3->getPosition().x<=-(road3->getContentSize().width))
    {
        road3->setPosition(Vec2((road2->getPosition().x)+(road2->getContentSize().width*2),road2->getPosition().y));
    }

}