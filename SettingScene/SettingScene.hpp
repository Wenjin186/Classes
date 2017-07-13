//
//  SettingScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#ifndef SettingScene_hpp
#define SettingScene_hpp

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace ui;

class SettingScene : public cocos2d::Scene, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(SettingScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void setSceneHistory();
    
    void Save(Ref *sender);
    
    void Load(Ref *sender);
    
    void Option(Ref *sender);
    
    void Exit(Ref *sender);
    
    void Back(Ref *sender);
};

#endif /* SettingScene_hpp */
