//
//  CppGoodsBagInfo.cpp
//  youxi
//
//  Created by Qi on 2017/7/31.
//
//

#include "CppGoodsBagInfo.hpp"

CppGoodsBagInfo::CppGoodsBagInfo(vector<CppGbLevel *> gbVector){
    this->gbVector = gbVector;
}

CppGoodsBagInfo::~CppGoodsBagInfo(){

}

vector<CppGbLevel *> &CppGoodsBagInfo::getLevelInfo(){
    return gbVector;
}

CppGbLevel *CppGoodsBagInfo::getLevelInfoByLevel(int level){
    for(int i = 0; i < GOODSBAGINFO_MAX ; i++){
        auto li = gbVector.at(i);
        if(li->getLevel() == level){
            return li;
        }
    }
    return nullptr;
}

int CppGoodsBagInfo::getCapacityMax(){
    capacityMax = GOODSBAG_CAPACITY_MAX;
    return capacityMax;
}
