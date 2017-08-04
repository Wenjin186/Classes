//
//  GlobalInfoData.cpp
//  youxi
//
//  Created by Qi on 2017/7/29.
//
//

#include "GlobalInfoData.hpp"
#include "CppGbLevel.hpp"


GlobalInfoData::GlobalInfoData(GlobalInfo *info){
    this->info = info;
    
    for (int i = 0; i < GOODSBAGINFO_MAX; i++) {
        gbVector.push_back(new CppGbLevel(i, 0));
    }
    goodsBagInfo = new CppGoodsBagInfo(gbVector);
    
    for(int i=0; i< ALLGOODSINFO_MAX; i++){
        goodsInfoVector.push_back(new GoodsInfo(&info->allgoods_info.detail[i]));
    }
    allGoodsInfo = new CppAllGoodsInfo(goodsInfoVector);
}

GlobalInfoData::~GlobalInfoData(){
    CC_SAFE_DELETE(goodsBagInfo);
    for (int i = 0; i < GOODSBAGINFO_MAX; i++) {
        auto level = gbVector.at(i);
        CC_SAFE_DELETE(level);
    }
    CC_SAFE_DELETE(allGoodsInfo);
}

CppGoodsBagInfo *GlobalInfoData::getCppGoodsBagInfo(){
    return goodsBagInfo;
}

CppAllGoodsInfo *GlobalInfoData::getCppAllGoodsInfo(){
    return allGoodsInfo;
}


