//
//  OptionScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/9.
//
//

#ifndef OptionScene_hpp
#define OptionScene_hpp

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace ui;

class OptionScene : public Scene, public cocostudio::WidgetCallBackHandlerProtocol{
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    CREATE_FUNC(OptionScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void Back(Ref *sender);
    
    void Ui(Ref *sender);
    
    void Control(Ref *sender);
    
    void Sound(Ref *sender);
    
    void Graphic(Ref *sender);
};

#endif /* OptionScene_hpp */
