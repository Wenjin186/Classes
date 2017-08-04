//
//  CppSpringSeedTable.cpp
//  youxi
//
//  Created by Qi on 2017/8/2.
//
//

#include "CppSpringSeedTable.hpp"

CppSpringSeedTable::CppSpringSeedTable(vector<CppSeed *> seedVector){
    this->seedVector = seedVector;
}

CppSpringSeedTable::~CppSpringSeedTable(){
    //CC_SAFE_DELETE(si);
}

vector<CppSeed *> &CppSpringSeedTable::getSeedTable(){
    return seedVector;
}

CppSeed *CppSpringSeedTable::getSeedInfoById(int id){
    for(int i = 0; i < SPRINGSEEDTABLE_MAX; i++){
        auto si = seedVector.at(i);
        if(si->getSeedId() == id){
            return si;
        }
    }
    return nullptr;
}
