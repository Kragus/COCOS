#include "Flappy.h"
#include "Globals.h"

USING_NS_CC;


Flappy::Flappy(cocos2d::Layer *spawnLayer)


{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    FlappySprite = Sprite::create("bird1.png");
    FlappySprite->setPosition(Vec2(origin.x+ visibleSize.width/4,origin.y+visibleSize.height/2));
    Vector<SpriteFrame*> animFrames;
    FlappySprite->setScale(1.2);

    auto FlappyPhysics = PhysicsBody::createCircle(FlappySprite->getContentSize().width/2);
    FlappyPhysics->setCollisionBitmask(BIRD_COLSION_BITID);
    FlappyPhysics->setContactTestBitmask(true);
    FlappyPhysics->setDynamic(false);


    FlappySprite->setPhysicsBody(FlappyPhysics);






    animFrames.reserve(12);
    animFrames.pushBack(SpriteFrame::create("bird2.png", Rect(0,0,FlappySprite->getContentSize().width,FlappySprite->getContentSize().height)));
    animFrames.pushBack(SpriteFrame::create("bird1.png", Rect(0,0,FlappySprite->getContentSize().width,FlappySprite->getContentSize().height)));
    animFrames.pushBack(SpriteFrame::create("bird3.png",  Rect(0,0,FlappySprite->getContentSize().width,FlappySprite->getContentSize().height)));

    Animation* Anim = Animation::createWithSpriteFrames(animFrames,0.2);
    Animate * animate = Animate::create(Anim);
    FlappySprite->runAction(RepeatForever::create(animate));

    auto hoverUp = MoveBy::create(0.5,Vec2(0,2));
    auto hoverDown = MoveBy::create(0.5,Vec2(0,-2));

    hoverSequence = Sequence::createWithTwoActions(hoverUp,hoverDown);

    FlappySprite->runAction(RepeatForever::create(hoverSequence));


    spawnLayer->addChild(FlappySprite);





}

void Flappy::_stopHoverAction() {

    FlappySprite->stopAction(hoverSequence);

}