#include "StartGameScene.h"
#include "SimpleAudioEngine.h"



Scene* StartGameScene::createScene()
{
    return StartGameScene::create();
}

// on "init" you need to initialize your instance
bool StartGameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    background = Sprite::create("start_game/background.png");
    background->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    
    this->addChild(background);
    
    return true;
}

