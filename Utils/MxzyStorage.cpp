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
    return SUCCESS;
}
