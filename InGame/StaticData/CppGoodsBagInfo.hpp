//
//  CppGoodsBagInfo.hpp
//  youxi
//
//  Created by Qi on 2017/7/31.
//
//

#ifndef CppGoodsBagInfo_hpp
#define CppGoodsBagInfo_hpp

#include "CppGbLevel.hpp"

using namespace std;

class CppGoodsBagInfo{
public:
    CppGoodsBagInfo(vector<CppGbLevel *> gbVector);
    ~CppGoodsBagInfo();
    vector<CppGbLevel *> &getLevelInfo();
    CppGbLevel *getLevelInfoByLevel(int level);
    int getCapacityMax();
private:
    vector<CppGbLevel *> gbVector;
    int capacityMax;
};

#endif /* CppGoodsBagInfo_hpp */
