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
#include "GlobalInfoData.hpp"

extern "C"{
#include "MxzyDatabase.h"
}

USING_NS_CC;
using namespace std;

class ProtagonistData;

class MxzyStorage{
public:
    ~MxzyStorage();
    static MxzyStorage *getInstance();
    static void purge();
    FILE *getFilePointer();
    CharacterRow *getCharacterRow();
    CharacterTable *getCharacterTable();
    
    int gameStart(); //该方法在AppDelegate中调用，创建文件流，并读取数据到crow, crow会一直保存数据到游戏结束再释放
    int writeGlobalInfo(); //把全局常量数据写入.global.bin文件中
    
    //下面为该类常用调用方法 通常使用
    // auto storage = MxzyStorage::getInstance();
    // ProtagonistData *pro_data = storage->getProtagonistDataById(storage->getCurrentProId());来返回一个对象专门操作和当前角色有关的数据
    int createNewProtagonist(); //创建一个角色，成功返回创建角色的ID，失败返回ERROR
    ProtagonistData *getProtagonistDataById(int id); //获得指定角色ID的数据
    GlobalInfoData *getGlobalInfoData(); //获得全局信息数据
    void setCurrentProId(int id); //设置当前角色ID
    int getCurrentProId(); //获得当前角色ID

    
    
private:
    FILE *fp;
    CharacterRow *crow;
    CharacterTable *table;
    int gameOver(); //该方法在本类的析构函数中被调用，释放所有资源
    
    static MxzyStorage *_storage;
    static ProtagonistData *_data;
    static GlobalInfoData *_globalData;
    FILE *fp_global;
    GlobalInfo *info;
    int current_id;
};

class ProtagonistData{
public:
    ProtagonistData(CharacterRow *crow);
    ~ProtagonistData();
    void setId(int id);
    int getId();
    
    void initWithGoodsBag();
    
    void setName(string &name);
    string &getName();
    GoodsBag *getGoodsBag();
private:
    string name;
    CharacterRow *crow;
    GoodsBag *bag;
};

#endif /* MxzyStorage_hpp */
