//
//  Sheep.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/21.
//
//

#include "Sheep.hpp"

bool Sheep::initWithFile(const std::string &filename){
    if ( ! Sprite::initWithFile(filename) ) {
        return false;
    }
    scheduleUpdate();
    return true;
}

Sheep *Sheep::create(const string &filename){
    
    Sheep *sheep = new (std::nothrow) Sheep();
    if (sheep && sheep->initWithFile(filename))
    {
        sheep->autorelease();
        return sheep;
    }
    CC_SAFE_DELETE(sheep);
    return nullptr;
}

//每个羊对象每一帧调用的方法
void Sheep::update(float delta){
    
}
