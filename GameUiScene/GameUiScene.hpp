//
//  GameUiScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/8.
//
//

#ifndef GameUiScene_hpp
#define GameUiScene_hpp

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace ui;

class GameUiScene : public Scene, public cocostudio::WidgetCallBackHandlerProtocol{
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    CREATE_FUNC(GameUiScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void Diary(Ref *sender);
    
    void Settings(Ref *sender);
    
    void Trade(Ref *sender);
};

#endif /* GameUiScene_hpp */
