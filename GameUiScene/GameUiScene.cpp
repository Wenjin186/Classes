//
//  GameUiScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/8.
//
//

#include "GameUiScene.hpp"
#include "GameUiSceneReader.hpp"
#include "SettingScene.hpp"
#include "DiaryScene.hpp"

Scene *GameUiScene::createScene(){
    CSLoader *loader = CSLoader::getInstance();
    loader->registReaderObject("GameUiSceneReader", (ObjectFactory::Instance)GameUiSceneReader::getInstance);
    Scene *scene = (Scene *)loader->createNode("game_ui/GameUiScene.csb");
    return scene;
}

bool GameUiScene::init(){
    if (!Scene::init()) {
        return false;
    }
    return true;
}

Widget::ccWidgetClickCallback GameUiScene::onLocateClickCallback(const std::string &callBackName){

    if (callBackName=="Diary") {
        return CC_CALLBACK_1(GameUiScene::Diary, this);
    }else if (callBackName=="Settings"){
        return CC_CALLBACK_1(GameUiScene::Settings, this);
    }else if (callBackName=="Trade"){
        return CC_CALLBACK_1(GameUiScene::Trade, this);
    }
    
    return nullptr;
}

void GameUiScene::Diary(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(DiaryScene::createScene());
}

void GameUiScene::Settings(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(SettingScene::createScene());
}

void GameUiScene::Trade(cocos2d::Ref *sender){
    CCLOG("Trade!");
}
