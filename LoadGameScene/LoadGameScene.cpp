//
//  LoadGameScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/10.
//
//

#include "LoadGameScene.hpp"
#include "LoadGameSceneReader.hpp"
#include "StartGameScene.h"
#include "NewGameScene.h"
#include "HistoryUtil.hpp"
#include "SettingScene.hpp"
#include "MxzyStorage.hpp"

Scene *LoadGameScene::createScene(){
    CSLoader *loader = CSLoader::getInstance();
    loader->registReaderObject("LoadGameSceneReader", (ObjectFactory::Instance)LoadGameSceneReader::getInstance);
    Scene *scene = (Scene *)loader->createNode("load_game/LoadGameScene.csb");
    return scene;
}

bool LoadGameScene::init(){
    if (!Scene::init()) {
        return false;
    }
    return true;
}

void LoadGameScene::onEnter(){
    Scene::onEnter();
    
    TextField *char1 = (TextField *)getChildByName("CharacterRow1");
    TextField *char2 = (TextField *)getChildByName("CharacterRow2");
    TextField *char3 = (TextField *)getChildByName("CharacterRow3");
    
    auto storage = MxzyStorage::getInstance();
    
    ProtagonistData *data1 = storage->getProtagonistDataById(1);
    ProtagonistData *data2 = storage->getProtagonistDataById(2);
    ProtagonistData *data3 = storage->getProtagonistDataById(3);
    
    if (data1 == nullptr) {
        char1->setString("No Record");
    }else
        char1->setString(data1->getName());
    
    if (data2 == nullptr) {
        char2->setString("No Record");
    }else
        char2->setString(data2->getName());
    
    if (data3 == nullptr) {
        char3->setString("No Record");
    }else
        char3->setString(data3->getName());
}

void LoadGameScene::onEnterTransitionDidFinish(){
    Scene::onEnterTransitionDidFinish();
    if (HistoryUtil::getInstance()->checkSceneHistoryWithoutPop("SettingScene")) {
        Button *button = (Button *)this->getChildByName("NewGameButton");
        button->setEnabled(false);
    }
}

Widget::ccWidgetClickCallback LoadGameScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="Back") {
        return CC_CALLBACK_1(LoadGameScene::Back, this);
    }else if (callBackName=="NewGame"){
        return CC_CALLBACK_1(LoadGameScene::NewGame, this);
    }else if (callBackName=="Load1"){
        return CC_CALLBACK_1(LoadGameScene::Load1, this);
    }else if (callBackName=="Load2"){
        return CC_CALLBACK_1(LoadGameScene::Load2, this);
    }else if (callBackName=="Load3"){
        return CC_CALLBACK_1(LoadGameScene::Load3, this);
    }
    
    return nullptr;
}

void LoadGameScene::Back(cocos2d::Ref *sender){
    if (HistoryUtil::getInstance()->checkSceneHistory("StartGameScene")) {
        auto director = Director::getInstance();
        director->replaceScene(StartGameScene::createScene());
    }else if (HistoryUtil::getInstance()->checkSceneHistory("SettingScene")){
        auto director = Director::getInstance();
        director->replaceScene(SettingScene::createScene());
    }
}

void LoadGameScene::NewGame(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(NewGameScene::createScene());
}

void LoadGameScene::Load1(cocos2d::Ref *sender){
    CCLOG("Load1");
}

void LoadGameScene::Load2(cocos2d::Ref *sender){
    CCLOG("Load2");
}

void LoadGameScene::Load3(cocos2d::Ref *sender){
    CCLOG("Load3");
}
