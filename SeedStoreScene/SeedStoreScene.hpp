//
//  SeedStoreScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/27.
//
//

#ifndef SeedStoreScene_hpp
#define SeedStoreScene_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
#include "Protagonist.hpp"
#include "SeedSeller.hpp"

USING_NS_CC;
using namespace ui;

class SeedStoreScene : public Scene, public cocostudio::WidgetCallBackHandlerProtocol{
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    void onEnter();
    
    CREATE_FUNC(SeedStoreScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void Diary(Ref *sender);
    
    void Settings(Ref *sender);
    
    void Trade(Ref *sender);
    
    virtual void update(float delta);
    
private:
    SeedSeller *seller = nullptr;
    Protagonist *pro;
    TMXTiledMap *map = nullptr;
    TMXObjectGroup *group = nullptr;
    ValueMap InsideDoorLeft;
    ValueMap table1;
    void judgeLdoorCollision();
    void judgeTable1Collision();
    
    
};

#endif /* SeedStoreScene_hpp */
