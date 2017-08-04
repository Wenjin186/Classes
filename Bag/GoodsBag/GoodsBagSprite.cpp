//
//  GoodsBagSprite.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/8/3.
//
//

#include "GoodsBagSprite.hpp"

bool GoodsBagSprite::initWithFile(const string &filename){
    if ( ! Sprite::initWithFile(filename) ) {
        return false;
    }
    
    return true;
}

GoodsBagSprite *GoodsBagSprite::create(){
    GoodsBagSprite *obj = new (std::nothrow) GoodsBagSprite();
    if (obj && obj->initWithFile("bags/itembag/goods_bag.png")) {
        obj->autorelease();
        return obj;
    }
    CC_SAFE_DELETE(obj);
    return nullptr;
}
