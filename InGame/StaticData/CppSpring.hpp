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

extern "C"{
#include "MxzyDatabase.h"
}

using namespace std;

class CppSpring{
public:
    CppSpring(Spring *spr);
    ~CppSpring();
private:
    Spring *spr;

};

#endif /* CppSpring_hpp */
