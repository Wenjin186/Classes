//
//  RelationshipScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#ifndef RelationshipScene_hpp
#define RelationshipScene_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace ui;

class RelationshipScene : public Scene, public cocostudio::WidgetCallBackHandlerProtocol{
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    void onEnterTransitionDidFinish();
    
    CREATE_FUNC(RelationshipScene);
    
    virtual Widget::ccWidgetClickCallback onLocateClickCallback(const std::string &callBackName);
    
    void Animal(Ref *sender);
    
    void Residents(Ref *sender);
    
    void SpeicalFriend(Ref *sender);
    
    void Employee(Ref *sender);
    
    void Back(Ref *sender);
};


#endif /* RelationshipScene_hpp */
