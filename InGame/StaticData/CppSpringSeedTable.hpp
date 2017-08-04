//
//  CppSpringSeedTable.hpp
//  youxi
//
//  Created by Qi on 2017/8/2.
//
//

#ifndef CppSpringSeedTable_hpp
#define CppSpringSeedTable_hpp

#include "CppSeed.hpp"
using namespace std;

extern "C"{
#include "MxzyDatabase.h"
}

class CppSpringSeedTable{
public:
    CppSpringSeedTable(vector<CppSeed *> seedVector);
    ~CppSpringSeedTable();
    vector<CppSeed *> &getSeedTable();
    CppSeed *getSeedInfoById(int id);
private:
    vector<CppSeed *> seedVector;
};

#endif /* CppSpringSeedTable_hpp */
