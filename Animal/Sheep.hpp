//
//  Sheep.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/21.
//
//

#ifndef Sheep_hpp
#define Sheep_hpp

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class Sheep : public Sprite{
public:
    static Sheep *create(const string &filename);
    virtual bool initWithFile(const std::string& filename);
    virtual void update(float delta);
};


#endif /* Sheep_hpp */
