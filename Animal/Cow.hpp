//
//  Cow.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/21.
//
//

#ifndef Cow_hpp
#define Cow_hpp

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class Cow : public Sprite{
public:
    static Cow *create(const string &filename);
    virtual bool initWithFile(const std::string& filename);
    virtual void update(float delta);
};

#endif /* Cow_hpp */
