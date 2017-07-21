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
    FILE *fp = NULL;
    int ret = createOrGetLocalStorage(&fp, "storage.bin");
    if (ret == ERROR) {
        CCLOG("create or get local storage failture");//以后会修改这里，如果读取失败 调到处理错误的场景
    }
    closeLocalStorage(fp);
    
    auto director = Director::getInstance();
    director->replaceScene(WholeFarmScene::createScene());
}

void NewGameScene::BackButton(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(StartGameScene::createScene());
}
