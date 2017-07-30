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

extern "C"{
#include "MxzyDatabase.h"
}

using namespace std;

class GlobalInfoData{
public:
    GlobalInfoData(GlobalInfo *info);
    ~GlobalInfoData();
    //GoodsInfo *getGoodsInfoById(int id);

private:
    string name;
    GlobalInfo *info;
    
 //   vector<object>
};

#endif /* GlobalInfoData_hpp */
