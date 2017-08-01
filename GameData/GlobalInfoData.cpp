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
    
}

GlobalInfoData::~GlobalInfoData(){
    CC_SAFE_DELETE(goodsBagInfo);
}

CppGoodsBagInfo *GlobalInfoData::getCppGoodsBagInfo(){
    GoodsBagInfo *temp = &info->goodsbag_info;
    vector<CppGbLevel *> tempV;
    
    for (int i = 0; i < GOODSBAGINFO_MAX; i++, temp++) {
        auto cg = new CppGbLevel(temp->levels[i].bag_level, temp->levels[i].bag_capacity);
        tempV.push_back(cg);
    }
    
    goodsBagInfo = new CppGoodsBagInfo(tempV);
    return goodsBagInfo;
}



