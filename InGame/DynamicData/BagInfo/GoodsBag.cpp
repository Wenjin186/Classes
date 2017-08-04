//
//  GoodsBag.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/22.
//
//

#include "GoodsBag.hpp"
#include "MxzyStorage.hpp"

GoodsBag::GoodsBag(int current_level, int goodsbag_max){
    this->current_level = current_level;
    this->capacity = goodsbag_max;
    initWithGoodsVec();
}

GoodsBag::~GoodsBag(){
    int bag_max = MxzyStorage::getInstance()->getGlobalInfoData()->getCppGoodsBagInfo()->getCapacityMax();
    for (int i = 0 ; i < bag_max; i++) {
        CC_SAFE_DELETE(goods_vec.at(i));
    }
}

void GoodsBag::initWithGoodsVec(){
    int bag_max = MxzyStorage::getInstance()->getGlobalInfoData()->getCppGoodsBagInfo()->getCapacityMax();
    for (int i = 0; i < bag_max; i++ ) {
        goods_vec.push_back(new Goods(0,0));
    }
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
