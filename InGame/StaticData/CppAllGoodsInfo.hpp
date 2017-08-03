//
//  CppAllGoodsInfo.hpp
//  youxi
//
//  Created by Qi on 2017/8/1.
//
//

#ifndef CppAllGoodsInfo_hpp
#define CppAllGoodsInfo_hpp

#include "GoodsInfo.hpp"

class CppAllGoodsInfo{
public:
    CppAllGoodsInfo(vector<GoodsInfo *> goodsInfoVector);
    ~CppAllGoodsInfo();
    vector<GoodsInfo *> &getAllGoodsInfo();
    GoodsInfo *getGoodsInfoById(int id);
private:
    vector<GoodsInfo *> goodsInfoVector;
};


#endif /* CppAllGoodsInfo_hpp */
