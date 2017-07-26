//
//  SeedSeller.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/25.
//
//

#ifndef SeedSeller_hpp
#define SeedSeller_hpp

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class SeedSeller : public Sprite{
public:
    //static Protagonist *create(const string &filename);
    static SeedSeller *getInstance();
    virtual bool initWithFile(const std::string& filename);
    virtual void update(float delta);
    
private:
    static SeedSeller *create(const string &filename);
    static SeedSeller *create();
};

#endif /* SeedSeller_hpp */
