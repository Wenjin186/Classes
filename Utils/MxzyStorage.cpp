//
//  MxzyStorage.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/22.
//
//

#include "MxzyStorage.hpp"

MxzyStorage *MxzyStorage::_storage = nullptr;

MxzyStorage *MxzyStorage::getInstance(){
    
    if (!_storage) {
        _storage = new MxzyStorage();
        return _storage;
    }
    
    return _storage;
}

void MxzyStorage::purge(){
    CC_SAFE_FREE(MxzyStorage::_storage);
}

FILE *MxzyStorage::getFilePointer(){
    return fp;
}

CharacterRow *MxzyStorage::getCharacterRow(){
    return crow;
}

CharacterTable *MxzyStorage::getCharacterTable(){
    return table;
}

int MxzyStorage::gameStart(){
    int ret = createOrGetLocalStorage(&fp, "gameDefault.bin");
    if (ret == ERROR) {
        CCLOG("创建文件失败");
        return ret;
    }
    
    initCharacterTable(&table);
    toReadData(fp, table);
    return ret;
}

int MxzyStorage::gameOver(){
    toWriteData(fp, table);
    freeCharacterTable(table);
    closeLocalStorage(fp);
    
    CC_SAFE_DELETE(_data);
    return SUCCESS;
}

int MxzyStorage::createNewProtagonist(){
    int id = createCharacter(table);
    return id;
}

//当你获得该角色信息的时候，已经把CharacterRow赋值了
ProtagonistData *MxzyStorage::getProtagonistDataById(int id){
    int ret = getCharacterRowById(&crow, table, id);
    if (ret == ERROR) {
        CCLOG("没有该角色的任何信息");
        return nullptr;
    }
    _data = new ProtagonistData(crow);
    
    return _data;
}
