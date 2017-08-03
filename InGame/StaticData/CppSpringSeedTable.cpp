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

}

vector<CppSeed *> &CppSpringSeedTable::getSeedTable(){
    return seedVector;
}
