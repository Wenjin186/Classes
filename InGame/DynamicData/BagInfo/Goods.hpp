//
//  Goods.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/22.
//
//

#ifndef Goods_hpp
#define Goods_hpp

#include "cocos2d.h"
using namespace std;

class Goods{
public:
    ~Goods();
    Goods(int goods_id, int amount);
    void addAnother();
    int getGoodsId();
    int getGoodsAmount();
    int getGoodsMaxStack();
private:
    int goods_id;
    int amount;
};

#endif /* Goods_hpp */
