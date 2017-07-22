//
//  LoadGameScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/10.
//
//

#ifndef LoadGameScene_hpp
#define LoadGameScene_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace ui;

class LoadGameScene : public Scene, public cocostudio::WidgetCallBackHandlerProtocol{
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    void onEnter();
    
    void onEnterTransitionDidFinish();
    
    CREATE_FUNC(LoadGameScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void Back(Ref *sender);
    
    void NewGame(Ref *sender);
    
    void Load1(Ref *sender);
    
    void Load2(Ref *sender);
    
    void Load3(Ref *sender);
};

#endif /* LoadGameScene_hpp */
