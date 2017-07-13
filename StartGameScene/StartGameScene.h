#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace ui;

class StartGameScene : public cocos2d::Scene, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(StartGameScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void setSceneHistory();
    
    void newGame(Ref *sender);
    
    void option (Ref *sender);
    
    void exitGame(Ref *sender);
    
    void loadGame(Ref *sender);
    
private:
    Scene *scene;
};

#endif // __HELLOWORLD_SCENE_H__
