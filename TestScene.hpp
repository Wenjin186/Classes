//
//  TestScene.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/8.
//
//

#ifndef TestScene_hpp
#define TestScene_hpp

#include "cocos2d.h"
USING_NS_CC;

class TestScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(TestScene);
    
};

#endif /* TestScene_hpp */
