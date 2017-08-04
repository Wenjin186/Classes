//
//  GoodsBag.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/22.
//
//

#ifndef GoodsBag_hpp
#define GoodsBag_hpp


#include "Goods.hpp"
extern "C"{
#include "MxzyDatabase.h"
}

class GoodsBag{
public:
    GoodsBag(int current_level, int goodsbag_max);
    ~GoodsBag();
    
    void initWithGoodsVec();
    
    void setCurrentLevel(int current_level);
    
    int getCurrentLevel();
    
    int getGoodsBagCapacity();
    
    
private:
    int current_level;
    int capacity;
    std::vector<Goods *> goods_vec;
};

#endif /* GoodsBag_hpp */
