//
//  GoodsInfo.cpp
//  youxi
//
//  Created by Qi on 2017/7/29.
//
//

#include "GoodsInfo.hpp"

GoodsInfo::GoodsInfo(GoodsDetail *goodsDetil){
    this->goodsDetail = goodsDetil;
}

GoodsInfo::~GoodsInfo(){

}

void GoodsInfo::setGoodsName(string &goodsName){
    strcpy(goodsDetail->goods_name,goodsName.c_str());
}

string &GoodsInfo::getGoodsName(){
    goodsName = string(goodsDetail->goods_name);
    return goodsName;
}
