//
//  SeedSeller.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/25.
//
//

#include "SeedSeller.hpp"

bool SeedSeller::initWithFile(const std::string &filename){
    if ( ! Sprite::initWithFile(filename) ) {
        return false;
    }
    scheduleUpdate();
    return true;
}

SeedSeller *SeedSeller::create(){
    SeedSeller *seller = new (std::nothrow) SeedSeller();
    if (seller && seller->init())
    {
        seller->autorelease();
        return seller;
    }
    CC_SAFE_DELETE(seller);
    return nullptr;
}

SeedSeller *SeedSeller::create(const string &filename){
    SeedSeller *seller = new (std::nothrow) SeedSeller();
    if (seller && seller->initWithFile(filename))
    {
        seller->autorelease();
        return seller;
    }
    CC_SAFE_DELETE(seller);
    return nullptr;
}

SeedSeller *SeedSeller::getInstance(){
    SeedSeller *seller = SeedSeller::create();
    
    seller->setTexture("character/guy-1/1F1.png");
    
    auto animation = Animation::create();
    animation->addSpriteFrameWithFile("character/guy-1/1R1.png");
    animation->addSpriteFrameWithFile("character/guy-1/1R2.png");
    animation->addSpriteFrameWithFile("character/guy-1/1R3.png");
    animation->setDelayPerUnit(3.0f/15.0f);
    //animation->setRestoreOriginalFrame(true);
    
    
    auto animate = Animate::create(animation);
    
    auto repeatanimate = RepeatForever::create(animate);
    auto moveTo = MoveTo::create(10.f, seller->getPosition()+Vec2(1024, 0));
    
    //seller->runAction(repeatanimate);
    //seller->runAction(moveTo);
    
    return seller;
}

void SeedSeller::update(float delta){
    
}


