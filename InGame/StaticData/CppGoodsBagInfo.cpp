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
