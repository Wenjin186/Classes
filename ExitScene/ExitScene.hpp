//
//  ExitScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/10.
//
//

#ifndef ExitScene_hpp
#define ExitScene_hpp

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace ui;

class ExitScene : public cocos2d::Scene, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(ExitScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void Title(Ref *sender);
    
    void Desktop(Ref *sender);
    
    void Back(Ref *sender);
};

#endif /* ExitScene_hpp */
