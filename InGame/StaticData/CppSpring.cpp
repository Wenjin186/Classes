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
        //seedVector.push_back();
    }
    
}

CppSpring::~CppSpring(){

}

CppSpringSeedTable *CppSpring::getCppSpringSeedTable(){
    return springSeedTable;
}
