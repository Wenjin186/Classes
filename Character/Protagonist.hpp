//
//  Protagonist.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/14.
//
//

#ifndef Protagonist_hpp
#define Protagonist_hpp

#define RIGHT_MOVE 0
#define LEFT_MOVE 1
#define UP_MOVE 2
#define DOWN_MOVE 3

#include "cocos2d.h"
#include "GoodsBag.hpp"

USING_NS_CC;
using namespace std;

class Protagonist : public Sprite{
public:

    //Protagonist();
    ~Protagonist();
    static Protagonist *getInstance();
    virtual bool initWithFile(const std::string& filename);
    virtual bool init();
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
    static Protagonist *create();
    static Protagonist *create(const string &filename);
    
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
    Animation *leftMoveAni = nullptr;
    Animation *rightMoveAni = nullptr;
    Animation *downMoveAni = nullptr;
    Animation *upMoveAni = nullptr;
    
    Animate *rightMoveAnimate = nullptr;
    Animate *leftMoveAnimate = nullptr;
    Animate *downMoveAnimate = nullptr;
    Animate *upMoveAnimate = nullptr;
    
    RepeatForever *leftRepeat = nullptr;
    RepeatForever *rightRepeat = nullptr;
    RepeatForever *downRepeat = nullptr;
    RepeatForever *upRepeat = nullptr;
    
    string face = "";
};

#endif /* Protagonist_hpp */
