//
//  ProtagonistData.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/23.
//
//

#include "ProtagonistData.hpp"

ProtagonistData::ProtagonistData(CharacterRow *crow){
    this->crow = crow;
}

ProtagonistData::~ProtagonistData(){
    CC_SAFE_DELETE(bag);
}

void ProtagonistData::setId(int id){
    crow->character_id = id;
}

int ProtagonistData::getId(){
    return crow->character_id;
}

void ProtagonistData::setName(string &name){
    strcpy(crow->character_name, name.c_str());
}

string  &ProtagonistData::getName(){
    name = string(crow->character_name);
    return name;
}

GoodsBag *ProtagonistData::getGoodsBag(){
    int level = crow->bag.bag_level;
    int amount = 0;
    
    MxzyStorage::getInstance()->getGlobalInfoData()->
    
    for (int i = 0; i < GOODSBAGINFO_MAX; i++) {
        if (level == info->goodsbag_info.levels[i].bag_level ){
            amount = info->goodsbag_info.levels[i].bag_capacity;
            break;
        }
    }
    
    
    bag = new GoodsBag(level, amount);
    return bag;
}
