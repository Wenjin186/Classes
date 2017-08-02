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
        gbVector.push_back(new CppGbLevel(0, 0));
    }
    
    for(int i=0; i< ALLGOODSINFO_MAX; i++){
        goodsInfoVector.push_back(new GoodsInfo(info->allgoods_info.detail));
    }
    
}

GlobalInfoData::~GlobalInfoData(){
    CC_SAFE_DELETE(goodsBagInfo);
    for (int i = 0; i < GOODSBAGINFO_MAX; i++) {
        auto level = gbVector.at(i);
        CC_SAFE_DELETE(level);
    }
}

CppGoodsBagInfo *GlobalInfoData::getCppGoodsBagInfo(){
 //   GoodsBagInfo *temp = &info->goodsbag_info;
    
    for (int i = 0; i < GOODSBAGINFO_MAX; i++) {
 //       CppGbLevel *level = gbVector.at(i);
        //level->setLevel();
        //level->setCapacity();
    }
    
    goodsBagInfo = new CppGoodsBagInfo(gbVector);
    return goodsBagInfo;
}

CppAllGoodsInfo *GlobalInfoData::getCppAllGoodsInfo(){
    allGoodsInfo = new CppAllGoodsInfo(goodsInfoVector);
    return allGoodsInfo;
    
}


