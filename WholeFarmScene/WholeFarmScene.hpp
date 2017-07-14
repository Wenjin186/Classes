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
#include "Protagonist.hpp"

USING_NS_CC;
using namespace ui;

class WholeFarmScene : public Scene, public cocostudio::WidgetCallBackHandlerProtocol{
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    void onEnterTransitionDidFinish();
    
    CREATE_FUNC(WholeFarmScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void Diary(Ref *sender);
    
    void Settings(Ref *sender);
    
    void Trade(Ref *sender);

private:
    Protagonist *pro = nullptr;
};

#endif /* GameUiScene_hpp */
