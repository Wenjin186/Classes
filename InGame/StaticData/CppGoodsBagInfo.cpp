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

vector<CppGbLevel *> &CppGoodsBagInfo::getLevelInfo(){
    return gbVector;
}

CppGbLevel *CppGoodsBagInfo::getLevelInfoById(int id){
    for(int i = 0; i < GOODSBAGINFO_MAX ; i++){
        auto li = gbVector.at(i);
        if(li->getLevel() == id){
            return li;
        }
    }
    return nullptr;
}
