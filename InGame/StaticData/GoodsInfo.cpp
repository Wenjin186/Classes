//
//  GoodsInfo.cpp
//  youxi
//
//  Created by Qi on 2017/7/29.
//
//

#include "GoodsInfo.hpp"

GoodsInfo::GoodsInfo(GoodsDetail *goodsDetail){
    this->goodsDetail = goodsDetail;
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

void GoodsInfo::setGoodsId(int goodsId){
    goodsDetail->goods_id = goodsId;
}

int GoodsInfo::getGoodsId(){
    return goodsDetail->goods_id;
}

void GoodsInfo::setPurchasePrice(double purchasePrice){
    goodsDetail->purchase_price = purchasePrice;
}

double GoodsInfo::getPurchasePrice(){
    return goodsDetail->purchase_price;
}

void GoodsInfo::setSellPrice(double sellPrice){
    goodsDetail->sell_price = sellPrice;
}

double GoodsInfo::getSellPrice(){
    return goodsDetail->sell_price;
}

void GoodsInfo::setGoodsType(int goodsType){
    goodsDetail->goods_type = goodsType;
}

int GoodsInfo::getGoodsType(){
    return goodsDetail->goods_type;
}

void GoodsInfo::setGoodsMax(int goodsMax){
    goodsDetail->goods_max = goodsMax;
}

int GoodsInfo::getGoodsMax(){
    return goodsDetail->goods_max;
}










