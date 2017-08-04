//
//  CppSpring.hpp
//  youxi
//
//  Created by Qi on 2017/8/2.
//
//

#ifndef CppSpring_hpp
#define CppSpring_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "CppSpringSeedTable.hpp"

extern "C"{
#include "MxzyDatabase.h"
}

using namespace std;

class CppSpring{
public:
    CppSpring(Spring *spr);
    ~CppSpring();
    CppSpringSeedTable *getCppSpringSeedTable();
private:
    Spring *spr;
    vector<CppSeed *> seedVector;
    CppSpringSeedTable *springSeedTable = nullptr;
};

#endif /* CppSpring_hpp */
