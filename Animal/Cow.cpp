//
//  Cow.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/21.
//
//

#include "Cow.hpp"

//初始化羊对象所有方法放在这里
bool Cow::initWithFile(const std::string &filename){
    if ( ! Sprite::initWithFile(filename) ) {
        return false;
    }
    
    scheduleUpdate();
    return true;
}

Cow *Cow::create(const string &filename){
    Cow *cow = new (std::nothrow) Cow();
    if (cow && cow->initWithFile(filename))
    {
        cow->autorelease();
        return cow;
    }
    CC_SAFE_DELETE(cow);
    return nullptr;
}

//每一帧调用的方法放在这里
void Cow::update(float delta){
    
}
