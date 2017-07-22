//
//  ExitScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/10.
//
//

#include "ExitScene.hpp"
#include "ExitSceneReader.hpp"
#include "StartGameScene.h"
#include "WholeFarmScene.hpp"
#include "HistoryUtil.hpp"
#include "MxzyStorage.hpp"

Scene* ExitScene::createScene()
{
    CSLoader *instance = CSLoader::getInstance();
    instance->registReaderObject("ExitSceneReader", (ObjectFactory::Instance)ExitSceneReader::getInstance);
    Scene *node = (Scene *)instance->createNode("exit/ExitScene.csb");
    return node;
}

bool ExitScene::init()
{
    if ( !Scene::init() )
        return false;
    
    return true;
}

Widget::ccWidgetClickCallback ExitScene::onLocateClickCallback(const std::string &callBackName){
    if (callBackName=="Back") {
        return CC_CALLBACK_1(ExitScene::Back, this);
    }else if (callBackName=="Title"){
        return CC_CALLBACK_1(ExitScene::Title, this);
    }else if (callBackName=="Desktop"){
        return CC_CALLBACK_1(ExitScene::Desktop, this);
    }
    
    return nullptr;
}

void ExitScene::Back(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(WholeFarmScene::createScene());
}

void ExitScene::Title(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(StartGameScene::createScene());
}

void ExitScene::Desktop(cocos2d::Ref *sender){
    HistoryUtil::purge();
    MxzyStorage::getInstance()->gameOver(); //释放CharacterTable 保存文件
    MxzyStorage::purge();
    Director::getInstance()->end();
}
