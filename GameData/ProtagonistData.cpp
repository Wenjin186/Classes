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
