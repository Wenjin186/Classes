//
//  LogScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#ifndef LogScene_hpp
#define LogScene_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace ui;

class LogScene : public Scene, public cocostudio::WidgetCallBackHandlerProtocol{
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    void onEnterTransitionDidFinish();
    
    CREATE_FUNC(LogScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void Asset(Ref *sender);
    
    void Info(Ref *sender);
    
    void Objective(Ref *sender);
    
    void Trade(Ref *sender);
    
    void Back(Ref *sender);
};


#endif /* LogScene_hpp */
