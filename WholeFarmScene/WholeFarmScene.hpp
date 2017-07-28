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
    void onEnter();
    
    CREATE_FUNC(WholeFarmScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void setSceneHistory();
    
    void Diary(Ref *sender);
    
    void Settings(Ref *sender);
    
    void Trade(Ref *sender);
    
    virtual void update(float delta);
    
    
    //测试方法
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);

private:
    Protagonist *pro = nullptr;
    EventListenerKeyboard *keyListener = nullptr;
    TMXTiledMap *map = nullptr;
    TMXObjectGroup *group = nullptr;
    
    ValueMap niupengDoor;
    ValueMap seedStoreDoor;
    
    Camera *camera = nullptr;
    Layer *button_layer = nullptr;
    void judgeNiuPengDoorCollision();
    void repositionCamera();
    void repositionButtonLayer();
    void judgeSeedStoreDoorCollision();
};

#endif /* GameUiScene_hpp */
