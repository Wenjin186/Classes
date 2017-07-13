//
//  MapScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#ifndef MapScene_hpp
#define MapScene_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace ui;

class MapScene : public Scene, public cocostudio::WidgetCallBackHandlerProtocol{
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    void onEnterTransitionDidFinish();
    
    CREATE_FUNC(MapScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void WorldMap(Ref *sender);
    
    void SeaVoyage(Ref *sender);
    
    void IslandMap(Ref *sender);
    
    void Back(Ref *sender);
};


#endif /* MapScene_hpp */
