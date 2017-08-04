//
//  InventoryScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#ifndef InventoryScene_hpp
#define InventoryScene_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
#include "GoodsBagSprite.hpp"

USING_NS_CC;
using namespace ui;

class InventoryScene : public Scene, public cocostudio::WidgetCallBackHandlerProtocol{
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    void onEnterTransitionDidFinish();
    
    CREATE_FUNC(InventoryScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void Craft(Ref *sender);
    
    void Items(Ref *sender);
    
    void Tool(Ref *sender);
    
    void Back(Ref *sender);
    
    void initGoodsBagLayer();
    
private:
    Layer *goodsBag_layer = nullptr;
    GoodsBagSprite *goodsBagSprite = nullptr;
};

#endif /* InventoryScene_hpp */
