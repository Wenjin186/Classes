//
//  GoodsBag.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/22.
//
//

#include "GoodsBag.hpp"

GoodsBag::GoodsBag(int current_level, int goodsbag_max){
    this->current_level = current_level;
    this->capacity = goodsbag_max;
    goods_vec = new std::vector<Goods>();
}

GoodsBag::~GoodsBag(){
    CC_SAFE_DELETE_ARRAY(goods_vec);
}

void GoodsBag::setCurrentLevel(int current_level){
    this->current_level = current_level;
}

int GoodsBag::getCurrentLevel(){
    return current_level;
}

int GoodsBag::getGoodsBagCapacity(){
    return capacity;
}
