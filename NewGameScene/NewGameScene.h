//
//  NewGameScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/7.
//
//

#ifndef NewGameScene_hpp
#define NewGameScene_hpp

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class NewGameScene : public cocos2d::Scene, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(NewGameScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void StartButton(Ref *sender);
    
    void BackButton(Ref *sender);
    
private:
    TextField *tf;
    
};

#endif /* NewGameScene_hpp */
