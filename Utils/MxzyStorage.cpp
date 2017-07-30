//
//  MxzyStorage.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/22.
//
//

#include "MxzyStorage.hpp"

MxzyStorage *MxzyStorage::_storage = nullptr;

MxzyStorage::~MxzyStorage(){
    gameOver();
}

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
    freeGlobalInfo(info);
    
    CC_SAFE_DELETE(_data);
    return SUCCESS;
}

int MxzyStorage::createNewProtagonist(){
    int id = createCharacter(table);
    
    if (id == ERROR) {
        return id;
    }
    
    getCharacterRowById(&crow, table, id);
    
    //创建新角色后的初始化工作放在这里
    crow->bag.bag_level = 1; //初始化背包等级
    
    
    return id;
}

//当你获得该角色信息的时候，已经把CharacterRow赋值了
ProtagonistData *MxzyStorage::getProtagonistDataById(int id){
    int ret = getCharacterRowById(&crow, table, id);
    if (ret == ERROR) {
        CCLOG("没有该角色的任何信息");
        return nullptr;
    }
    _data = new ProtagonistData(crow, info);
    
    return _data;
}

GlobalInfoData *MxzyStorage::getGlobalInfoData(){
    _globalData = new GlobalInfoData(info);
    
    return _globalData;
}

int MxzyStorage::writeGlobalInfo(){
    int ret = createOrGetGlobalInfoFile(&fp_global, ".global.bin");
    if (ret == ERROR) {
        CCLOG("创建GlobalInfo文件失败");
        return ERROR;
    }
    initGlobalInfo(&info);
    
    enterGlobalInfoDataBeforeSaving(info);
    
    toWriteGlobalInfo(fp_global, info);
    //freeGlobalInfo(info);
    closeGlobalInfoFile(fp_global);
    return SUCCESS;
}

void MxzyStorage::setCurrentProId(int id){
    this->current_id = id;
}

int MxzyStorage::getCurrentProId(){
    return current_id;
}
