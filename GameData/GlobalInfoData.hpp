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
#include "CppAllGoodsInfo.hpp"

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
    CppAllGoodsInfo *getCppAllGoodsInfo();
private:
    string name;
    GlobalInfo *info;
    CppGoodsBagInfo *goodsBagInfo = nullptr;
    vector<CppGbLevel *> gbVector;
    vector<GoodsInfo *> goodsInfoVector;
    CppAllGoodsInfo *allGoodsInfo = nullptr;
 //   vector<object>
};

#endif /* GlobalInfoData_hpp */
