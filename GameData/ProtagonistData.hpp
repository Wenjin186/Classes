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

extern "C"{
#include "MxzyDatabase.h"
}

using namespace std;

class ProtagonistData{
public:
    ProtagonistData(CharacterRow *crow);
    void setId(int id);
    int getId();
    
    void setName(string &name);
    string &getName();
private:
    string name;
    CharacterRow *crow;
};

#endif /* ProtagonistData_hpp */
