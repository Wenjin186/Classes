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

USING_NS_CC;
using namespace std;

class Protagonist : public Sprite{
public:
    static Protagonist *create(const string &filename);
    virtual bool initWithFile(const std::string& filename);
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
    void onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event);
    virtual void update(float delta);
private:
    bool upMove = false;
    bool downMove = false;
    bool rightMove = false;
    bool leftMove = false;
    EventListenerKeyboard *keyListener = nullptr;
};

#endif /* Protagonist_hpp */
