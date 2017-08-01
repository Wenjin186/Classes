//
//  CppGbLevel.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/31.
//
//

#include "CppGbLevel.hpp"

CppGbLevel::CppGbLevel(int level, int capacity){
    this->level = level;
    this->capacity = capacity;
}

CppGbLevel::~CppGbLevel(){

}

void CppGbLevel::setLevel(int level){
    this->level = level;
}

int CppGbLevel::getLevel(){
    return this->level;
}

void CppGbLevel::setCapacity(int capacity){
    this->capacity = capacity;
}

int CppGbLevel::getCapacity(){
    return this->capacity;
}
