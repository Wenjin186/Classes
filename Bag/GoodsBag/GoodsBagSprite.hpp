//
//  GoodsBagSprite.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/8/3.
//
//

#ifndef GoodsBagSprite_hpp
#define GoodsBagSprite_hpp

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class GoodsBagSprite : public Sprite {
public:
    static GoodsBagSprite *create();
    virtual bool initWithFile (const string &filename);
};

#endif /* GoodsBagSprite_hpp */
