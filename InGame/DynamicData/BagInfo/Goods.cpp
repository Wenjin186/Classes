//
//  Goods.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/22.
//
//

#include "Goods.hpp"

Goods::~Goods(){
    CCLOG("Goods has been deleted.");
}

Goods::Goods(int goods_id, int amount){
    CCLOG("hello world!");
    this->goods_id = goods_id;
    this->amount = amount;
}

void Goods::saveNewItem(int id, int amount){
    this->goods_id = id;
    this->amount += amount;
}

void Goods::addAnother(){
    amount++;
}

int Goods::getGoodsId(){
    return goods_id;
}

int Goods::getGoodsAmount(){
    return amount;
}


