//
//  Protagonist.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/14.
//
//

#include "Protagonist.hpp"

//static Protagonist *pro = nullptr;

Protagonist::~Protagonist(){
    rightRepeat->release();
    leftRepeat->release();
    downRepeat->release();
    upRepeat->release();
}

bool Protagonist::init(){
    if ( ! Sprite::init() ) {
        return false;
    }
    
    keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(Protagonist::onKeyPressed, this);
    keyListener->onKeyReleased = CC_CALLBACK_2(Protagonist::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
    
    scheduleUpdate();
    
    return true;
}

bool Protagonist::initWithFile(const std::string &filename){
    if ( ! Sprite::initWithFile(filename) ) {
        return false;
    }
    
    
    keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(Protagonist::onKeyPressed, this);
    keyListener->onKeyReleased = CC_CALLBACK_2(Protagonist::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
    
    rightMoveAni = Animation::create();
    leftMoveAni = Animation::create();
    downMoveAni = Animation::create();
    upMoveAni = Animation::create();
    
    rightMoveAni->addSpriteFrameWithFile("character/abandon/right2.png");
    rightMoveAni->addSpriteFrameWithFile("character/abandon/right3.png");
    rightMoveAni->addSpriteFrameWithFile("character/abandon/right4.png");
    rightMoveAni->addSpriteFrameWithFile("character/abandon/right1.png");
    rightMoveAni->setDelayPerUnit(3.0f/15.0f);
    rightMoveAni->setRestoreOriginalFrame(true);
    rightMoveAnimate = Animate::create(rightMoveAni);
    rightRepeat = RepeatForever::create(rightMoveAnimate);
    rightRepeat->retain();
    rightRepeat->setTag(RIGHT_MOVE);
    
    leftMoveAni->addSpriteFrameWithFile("character/abandon/left2.png");
    leftMoveAni->addSpriteFrameWithFile("character/abandon/left3.png");
    leftMoveAni->addSpriteFrameWithFile("character/abandon/left4.png");
    leftMoveAni->addSpriteFrameWithFile("character/abandon/left1.png");
    leftMoveAni->setDelayPerUnit(3.0f/15.0f);
    leftMoveAni->setRestoreOriginalFrame(true);
    leftMoveAnimate = Animate::create(leftMoveAni);
    leftRepeat = RepeatForever::create(leftMoveAnimate);
    leftRepeat->retain();
    leftRepeat->setTag(LEFT_MOVE);
    
    
    upMoveAni->addSpriteFrameWithFile("character/abandon/back2.png");
    upMoveAni->addSpriteFrameWithFile("character/abandon/back3.png");
    upMoveAni->addSpriteFrameWithFile("character/abandon/back4.png");
    upMoveAni->addSpriteFrameWithFile("character/abandon/back1.png");
    upMoveAni->setDelayPerUnit(3.0f/15.0f);
    upMoveAni->setRestoreOriginalFrame(true);
    upMoveAnimate = Animate::create(upMoveAni);
    upRepeat = RepeatForever::create(upMoveAnimate);
    upRepeat->retain();
    upRepeat->setTag(UP_MOVE);
    
    downMoveAni->addSpriteFrameWithFile("character/abandon/front2.png");
    downMoveAni->addSpriteFrameWithFile("character/abandon/front3.png");
    downMoveAni->addSpriteFrameWithFile("character/abandon/front4.png");
    downMoveAni->addSpriteFrameWithFile("character/abandon/front1.png");
    downMoveAni->setDelayPerUnit(3.0f/15.0f);
    downMoveAni->setRestoreOriginalFrame(true);
    downMoveAnimate = Animate::create(downMoveAni);
    downRepeat = RepeatForever::create(downMoveAnimate);
    downRepeat->retain();
    downRepeat->setTag(DOWN_MOVE);
    
    scheduleUpdate();
    return true;
}

Protagonist *Protagonist::create(){
    Protagonist *pro = new (std::nothrow) Protagonist();
    if (pro && pro->init())
    {
        pro->autorelease();
        return pro;
    }
    CC_SAFE_DELETE(pro);
    return nullptr;
}

Protagonist *Protagonist::create(const string &filename){
//    if (pro != nullptr) {
//        return pro;
//    }
    
    
    Protagonist *pro = new (std::nothrow) Protagonist();
    if (pro && pro->initWithFile(filename))
    {
        pro->autorelease();
        return pro;
    }
    CC_SAFE_DELETE(pro);
    return nullptr;
}

Protagonist *Protagonist::getInstance(){
    Protagonist *pro =  Protagonist::create("character/abandon/front1.png");
    
    
    return pro;
}

void Protagonist::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
    //CCLOG("Key pressed keycode = %d", keyCode);
    if (keyCode==EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
        //if (!leftMove && !upMove && !downMove)
        rightMove = true;
        leftMove = false;
        downMove = false;
        upMove = false;
        
    }
    else if (keyCode==EventKeyboard::KeyCode::KEY_LEFT_ARROW){
        rightMove = false;
        leftMove = true;
        downMove = false;
        upMove = false;
    }
    else if (keyCode==EventKeyboard::KeyCode::KEY_UP_ARROW){
        //if (!leftMove && !rightMove && !downMove)
        rightMove = false;
        leftMove = false;
        downMove = false;
        upMove = true;
    }
    else if (keyCode==EventKeyboard::KeyCode::KEY_DOWN_ARROW){
        //if (!leftMove && !upMove && !rightMove)
        rightMove = false;
        leftMove = false;
        downMove = true;
        upMove = false;
    }
}

void Protagonist::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
    //CCLOG("Key released keycode = %d", keyCode);
    if (keyCode==EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
        rightMove = false;
    }
    else if (keyCode==EventKeyboard::KeyCode::KEY_LEFT_ARROW){
        leftMove = false;
    }
    else if (keyCode==EventKeyboard::KeyCode::KEY_UP_ARROW){
        upMove = false;
    }
    else if (keyCode==EventKeyboard::KeyCode::KEY_DOWN_ARROW){
        downMove = false;
    }
}

void Protagonist::update(float delta){
    int speed = 6;
    if (rightMove==true) {
        face = "right";
        setPosition(getPosition()+Vec2(speed, 0));
        if (getActionByTag(RIGHT_MOVE) == nullptr) {
            stopAllActions();
            runAction(rightRepeat);
        }
    }
    if (upMove==true) {
        face = "up";
        setPosition(getPosition()+Vec2(0, speed));
        if (getActionByTag(UP_MOVE) == nullptr) {
            stopAllActions();
            runAction(upRepeat);
        }
    }
    if (leftMove==true){
        face = "left";
        setPosition(getPosition()-Vec2(speed, 0));
        if (getActionByTag(LEFT_MOVE) == nullptr) {
            stopAllActions();
            runAction(leftRepeat);
        }
    }
    if (downMove==true) {
        face = "down";
        setPosition(getPosition()-Vec2(0,speed));
        if (getActionByTag(DOWN_MOVE) == nullptr) {
            stopAllActions();
            runAction(downRepeat);
        }
    }
    if (!rightMove && !leftMove && !upMove && !downMove) {
        stopAllActions();
        if (face=="right") {
            setTexture("character/abandon/right1.png");
        }else if (face=="left"){
            setTexture("character/abandon/left1.png");
        }else if (face=="up"){
            setTexture("character/abandon/back1.png");
        }else if (face=="down"){
            setTexture("character/abandon/front1.png");
        }
    }
//        stopAllActions();
}

//void Protagonist::setProtagonistId(int id){
//    this->pro_id = id;
//}
//
//void Protagonist::setProtagonistName(string &str){
//    this->pro_name = str;
//}
//
//void Protagonist::setGoodsBag(int current_level, int goodsbag_max){
//    bag = new GoodsBag(current_level, goodsbag_max);
//}
//
//void Protagonist::freeGoodsBag(){
//    CC_SAFE_FREE(bag);
//}
//
//int Protagonist::getProtagonistId(){
//    return pro_id;
//}

