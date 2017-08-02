//
//  CppGbLevel.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/31.
//
//

#ifndef CppGbLevel_hpp
#define CppGbLevel_hpp

using namespace std;

extern "C"{
#include "MxzyDatabase.h"
}

class CppGbLevel{
public:
    CppGbLevel(int level, int capacity);
    ~CppGbLevel();
    
    void setLevel(int level);
    int getLevel();
    
    void setCapacity(int capacity);
    int getCapacity();
    
private:
    int level = 0;
    int capacity = 0;
};

#endif /* CppGbLevel_hpp */
