//
//  Protagonist.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/14.
//
//

#include "Protagonist.hpp"

//static Protagonist *pro = nullptr;

//Protagonist::Protagonist(){
//    //Sprite::Sprite();
//
//    
//    //runAction(rightRepeat);
//}

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
    
    rightMoveAni->addSpriteFrameWithFile("character/abandon/right1.png");
    rightMoveAni->addSpriteFrameWithFile("character/abandon/right2.png");
    rightMoveAni->addSpriteFrameWithFile("character/abandon/right3.png");
    rightMoveAni->addSpriteFrameWithFile("character/abandon/right4.png");
    rightMoveAni->setDelayPerUnit(3.0f/15.0f);
    rightMoveAni->setRestoreOriginalFrame(true);
    rightMoveAnimate = Animate::create(rightMoveAni);
    rightRepeat = RepeatForever::create(rightMoveAnimate);
    rightRepeat->retain();
    rightRepeat->setTag(RIGHT_MOVE);
    //runAction(rightRepeat);
    
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
        rightMove = true;
    }
    else if (keyCode==EventKeyboard::KeyCode::KEY_LEFT_ARROW){
        leftMove = true;
    }
    else if (keyCode==EventKeyboard::KeyCode::KEY_UP_ARROW){
        upMove = true;
    }
    else if (keyCode==EventKeyboard::KeyCode::KEY_DOWN_ARROW){
        downMove = true;
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
    int speed = 3;
    if (rightMove==true) {
        CCLOG("**************");
        setPosition(getPosition()+Vec2(speed, 0));
        if (getActionByTag(RIGHT_MOVE) == nullptr) {
            runAction(rightRepeat);
        }
    }
    if (upMove==true) {
        setPosition(getPosition()+Vec2(0, speed));
    }
    if (leftMove==true){
        setPosition(getPosition()-Vec2(speed, 0));
    }
    if (downMove==true) {
        setPosition(getPosition()-Vec2(0,speed));
    }
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

