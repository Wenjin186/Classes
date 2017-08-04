//
//  CppSpring.cpp
//  youxi
//
//  Created by Qi on 2017/8/2.
//
//

#include "CppSpring.hpp"

CppSpring::CppSpring(Spring *spr){
    this->spr = spr;
    
    for(int i = 0; i < SPRINGSEEDTABLE_MAX; i++){
        seedVector.push_back(new CppSeed(&spr->sstable.sd[i]));
    }
    springSeedTable = new CppSpringSeedTable(seedVector);
}

CppSpring::~CppSpring(){
    CC_SAFE_DELETE(springSeedTable);
    
    for(int i = 0; i < SPRINGSEEDTABLE_MAX; i++){
        auto seed = seedVector.at(1);
        CC_SAFE_DELETE(seed);
    }
    
}

CppSpringSeedTable *CppSpring::getCppSpringSeedTable(){
    return springSeedTable;
}
