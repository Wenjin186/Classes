//
//  MxzyStorage.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/22.
//
//

#ifndef MxzyStorage_hpp
#define MxzyStorage_hpp

#include "cocos2d.h"
#include "ProtagonistData.hpp"

extern "C"{
#include "MxzyDatabase.h"
}

USING_NS_CC;
using namespace std;

class MxzyStorage{
public:
    static MxzyStorage *getInstance();
    static void purge();
    FILE *getFilePointer();
    CharacterRow *getCharacterRow();
    CharacterTable *getCharacterTable();
    int gameStart();
    int gameOver();
    
    FILE *fp;
    CharacterRow *crow;
    CharacterTable *table;
    
    int createNewProtagonist();
    ProtagonistData *getProtagonistDataById(int id);
    
private:
    static MxzyStorage *_storage;
    ProtagonistData *_data;
};

#endif /* MxzyStorage_hpp */
