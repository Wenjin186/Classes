//
//  Protagonist.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/14.
//
//

#include "Protagonist.hpp"

bool Protagonist::initWithFile(const std::string &filename){
    if ( ! Sprite::initWithFile(filename) ) {
        return false;
    }
    keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(Protagonist::onKeyPressed, this);
    keyListener->onKeyReleased = CC_CALLBACK_2(Protagonist::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
    
    scheduleUpdate();
    return true;
}

Protagonist *Protagonist::create(const string &filename){
    
    Protagonist *pro = new (std::nothrow) Protagonist();
    if (pro && pro->initWithFile(filename))
    {
        pro->autorelease();
        return pro;
    }
    CC_SAFE_DELETE(pro);
    return nullptr;
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
        setPosition(getPosition()+Vec2(speed, 0));
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
