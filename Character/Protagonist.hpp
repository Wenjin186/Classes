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
    virtual bool init();
};

#endif /* Protagonist_hpp */
