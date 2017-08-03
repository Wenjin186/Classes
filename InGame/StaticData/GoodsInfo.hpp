//
//  GoodsInfo.hpp
//  youxi
//
//  Created by Qi on 2017/7/29.
//
//

#ifndef GoodsInfo_hpp
#define GoodsInfo_hpp

#include "cocos2d.h"

using namespace std;

extern "C"{
#include "MxzyDatabase.h"
}

class GoodsInfo{
public:
    GoodsInfo(GoodsDetail *goodsDetail);
    ~GoodsInfo();
    
    void setGoodsName(string &goodsName);
    string &getGoodsName();
    
    void setGoodsId(int goodsId);
    int getGoodsId();
    
    void setPurchasePrice(double purchasePrice);
    double getPurchasePrice();
    
    void setSellPrice(double sellPrice);
    double getSellPrice();
    
    void setGoodsType(int goodsType);
    int getGoodsType();
    
    void setGoodsMax(int goodsMax);
    int getGoodsMax();
    
    string &getImagePass();
private:
    GoodsDetail *goodsDetail;
    string goodsName;
    int goodsId;
    double purchasePrice;
    double sellPrice;
    string imagePath;
};

#endif /* GoodsInfo_hpp */
