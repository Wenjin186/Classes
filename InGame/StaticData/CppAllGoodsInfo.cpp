//
//  CppAllGoodsInfo.cpp
//  youxi
//
//  Created by Qi on 2017/8/1.
//
//

#include "CppAllGoodsInfo.hpp"

CppAllGoodsInfo::CppAllGoodsInfo(vector<GoodsInfo *> goodsInfoVector){
    this->goodsInfoVector = goodsInfoVector;
}

vector<GoodsInfo *> &CppAllGoodsInfo::getAllGoodsInfo(){
    return goodsInfoVector;
}

GoodsInfo *CppAllGoodsInfo::getGoodsInfoById(int id){
    for (int i = 0; i < ALLGOODSINFO_MAX; i++) {
        auto gi = goodsInfoVector.at(i);
        if (gi->getGoodsId() == id)
            return gi;
    }
    return nullptr;
}
