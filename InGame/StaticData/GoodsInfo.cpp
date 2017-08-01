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
    
}
