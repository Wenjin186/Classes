//
//  GlobalInfoData.hpp
//  youxi
//
//  Created by Qi on 2017/7/29.
//
//

#ifndef GlobalInfoData_hpp
#define GlobalInfoData_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "GoodsBag.hpp"
#include "CppGoodsBagInfo.hpp"

extern "C"{
#include "MxzyDatabase.h"
}

using namespace std;

class GlobalInfoData{
public:
    GlobalInfoData(GlobalInfo *info);
    ~GlobalInfoData();
    //GoodsInfo *getGoodsInfoById(int id);
    CppGoodsBagInfo *getCppGoodsBagInfo();
private:
    string name;
    GlobalInfo *info;
    CppGoodsBagInfo *goodsBagInfo = nullptr;
 //   vector<object>
};

#endif /* GlobalInfoData_hpp */
