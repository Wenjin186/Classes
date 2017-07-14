//
//  Protagonist.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/14.
//
//

#include "Protagonist.hpp"

bool Protagonist::init(){
    if ( ! Sprite::init() ) {
        return false;
    }
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
