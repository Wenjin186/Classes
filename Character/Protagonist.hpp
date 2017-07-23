//
//  Protagonist.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/14.
//
//

#ifndef Protagonist_hpp
#define Protagonist_hpp

#include "cocos2d.h"
#include "GoodsBag.hpp"

USING_NS_CC;
using namespace std;

class Protagonist : public Sprite{
public:
    static Protagonist *create(const string &filename);
    static Protagonist *getInstance();
    virtual bool initWithFile(const std::string& filename);
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);
    virtual void update(float delta);
    
    //int getProtagonistId();
    
//    //以下函数必须调用
//    void setProtagonistId(int id);
//    void setProtagonistName(string &str);
//    void setGoodsBag(int current_level, int goodsbag_max);
//    void freeGoodsBag();
    
    
private:
    bool upMove = false;
    bool downMove = false;
    bool rightMove = false;
    bool leftMove = false;
    EventListenerKeyboard *keyListener = nullptr;
    
    //角色Id
    int pro_id;
    string pro_name;
    
    //记得释放
    GoodsBag *bag = nullptr;
};

#endif /* Protagonist_hpp */
