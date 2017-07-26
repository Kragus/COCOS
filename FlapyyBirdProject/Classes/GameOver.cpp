
#include "SimpleAudioEngine.h"
#include "GameOver.h"
#include "MainGameScene.h"

USING_NS_CC;


// on "init" you need to initialize your instance
void GameOver::spawnMenu(cocos2d::Layer *spawnLayer,int currentScore) {

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto titleSprite = Sprite::create("game_over.png");
    titleSprite->setPosition(
            Vec2(origin.x + visibleSize.width *1.5, origin.y + visibleSize.height *0.8));
    titleSprite->setScale(2);
    spawnLayer->addChild(titleSprite);

    auto scoreBoard = Sprite::create("result_board.png");
    scoreBoard->setPosition(
            Vec2(origin.x + visibleSize.width *1.5, origin.y + visibleSize.height / 2));
    scoreBoard->setScale(2);
    spawnLayer->addChild(scoreBoard);
    auto userDefault = cocos2d::UserDefault::getInstance();

    auto highestScore = StringUtils::format("%02d",userDefault->getIntegerForKey("highestScore"));

    auto highScoreLabel = Label::createWithTTF(highestScore,"Minecrafter_3.ttf", 5,Size::ZERO,TextHAlignment::CENTER);
   scoreBoard->addChild(highScoreLabel,2);
    highScoreLabel->setPosition(Vec2(highScoreLabel->getPosition().x + scoreBoard->getContentSize().width*0.8, (highScoreLabel->getPosition().y +scoreBoard->getContentSize().height*0.2)));


    auto currentScoreLabel = Label::createWithTTF(StringUtils::format("%02d",currentScore),"Minecrafter_3.ttf", 5,Size::ZERO,TextHAlignment::CENTER);
    scoreBoard->addChild(currentScoreLabel,2);
    currentScoreLabel->setPosition(Vec2(currentScoreLabel->getPosition().x + scoreBoard->getContentSize().width*0.8, (currentScoreLabel->getPosition().y +scoreBoard->getContentSize().height*0.6)));

    if(currentScore>=50)
    {
        Sprite* medal = Sprite::create("medal_glod.png");
        scoreBoard->addChild(medal);
        medal->setPosition(Vec2(medal->getPosition().x+scoreBoard->getContentSize().width*0.2,medal->getPosition().y+scoreBoard->getContentSize().height*0.4));

    } else if(currentScore>=10)
    {
        Sprite* medal = Sprite::create("medal_silver.png");
        scoreBoard->addChild(medal);
        medal->setPosition(Vec2(medal->getPosition().x+scoreBoard->getContentSize().width*0.2,medal->getPosition().y+scoreBoard->getContentSize().height*0.4));
    }

    MenuItemImage *playButton;
    playButton = MenuItemImage::create("play_button.png", "play_button_clicked.png",
                                       CC_CALLBACK_1(GameOver::RestartGame, this));
    playButton->setPosition(Vec2(origin.x + visibleSize.width *1.5, origin.y + visibleSize.height * 0.25));
    playButton->setScale(2);
    Menu *gameOverMenu = Menu::create(playButton, NULL);
    gameOverMenu->setPosition(Point::ZERO);
    spawnLayer->addChild(gameOverMenu,2);

    auto moveTitle = MoveBy::create(0.5,Point(-visibleSize.width,0));
    auto moveBoard = MoveBy::create(0.5,Point(-visibleSize.width,0));
    auto moveButton = MoveBy::create(0.5,Point(-visibleSize.width,0));

    gameOverMenu->runAction(moveButton);
    scoreBoard->runAction(moveBoard);
    titleSprite->runAction(moveTitle);

}




void GameOver::RestartGame(Ref *sender)
{


    auto gameScene= MainGameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1,gameScene) );

}
