//
//  NewGameScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/7.
//
//

#include "NewGameScene.h"
#include "NewGameSceneReader.h"
#include "StartGameScene.h"
#include "WholeFarmScene.hpp"
#include "MxzyStorage.hpp"

extern "C"{
#include "MxzyDatabase.h"
}


Scene *NewGameScene::createScene(){
    CSLoader *instance = CSLoader::getInstance();
    instance->registReaderObject("NewGameSceneReader", (ObjectFactory::Instance)NewGameSceneReader::getInstance);
    Scene *node = (Scene *)instance->createNode("new_game/NewGameScene.csb");
    return node;
}

bool NewGameScene::init()
{
    if ( !Scene::init() )
        return false;

    return true;
}

Widget::ccWidgetClickCallback NewGameScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="StartButton") {
        return CC_CALLBACK_1(NewGameScene::StartButton, this);
    }else if (callBackName=="BackButton"){
        return CC_CALLBACK_1(NewGameScene::BackButton, this);
    }
    
    return nullptr;
}

//开始游戏,这里调用后台数据库的函数
void NewGameScene::StartButton(Ref *sender){
    tf = (TextField *)getChildByName("EnterNameTextField");
    string char_str = tf->getString();

    auto storage = MxzyStorage::getInstance();
    int pro_id = storage->createNewProtagonist();
    if (pro_id==ERROR) {
        CCLOG("角色满了，无法创建");
        return;
    }
    
    storage->setCurrentProId(pro_id);
    ProtagonistData *data= storage->getProtagonistDataById(storage->getCurrentProId());
    data->setName(char_str);
    
    auto director = Director::getInstance();
    director->replaceScene(WholeFarmScene::createScene());
}

void NewGameScene::BackButton(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(StartGameScene::createScene());
}
