//
//  NiuPengScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/16.
//
//

#ifndef NiuPengScene_hpp
#define NiuPengScene_hpp

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
#include "Protagonist.hpp"

USING_NS_CC;
using namespace ui;

class NiuPengScene : public cocos2d::Scene, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(NiuPengScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void onEnter();
    
    void setSceneHistory();
    
    void Diary(Ref *sender);
    
    void Trade (Ref *sender);
    
    void Settings(Ref *sender);
    
    void update(float delta);
    
private:
    Protagonist *pro = nullptr;
    TMXTiledMap *map = nullptr;
    TMXObjectGroup *group = nullptr;
    ValueMap niupengDoor;
};

#endif /* NiuPengScene_hpp */
