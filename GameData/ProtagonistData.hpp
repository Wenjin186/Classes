//
//  ProtagonistData.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/23.
//
//

#ifndef ProtagonistData_hpp
#define ProtagonistData_hpp

#include "cocos2d.h"
#include "GoodsBag.hpp"
#include "MxzyStorage.hpp"

extern "C"{
#include "MxzyDatabase.h"
}

using namespace std;

class ProtagonistData{
public:
    ProtagonistData(CharacterRow *crow);
    ~ProtagonistData();
    void setId(int id);
    int getId();
    
    void setName(string &name);
    string &getName();
    GoodsBag *getGoodsBag();
private:
    string name;
    CharacterRow *crow;
    GoodsBag *bag;
};

#endif /* ProtagonistData_hpp */
