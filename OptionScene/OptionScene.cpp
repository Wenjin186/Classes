//
//  OptionScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/9.
//
//

#include "OptionScene.hpp"
#include "OptionSceneReader.hpp"
#include "StartGameScene.h"
#include "HistoryUtil.hpp"
#include "SettingScene.hpp"

Scene *OptionScene::createScene(){
    CSLoader *loader = CSLoader::getInstance();
    loader->registReaderObject("OptionSceneReader", (ObjectFactory::Instance)OptionSceneReader::getInstance);
    Scene *scene = (Scene *)loader->createNode("option/OptionScene.csb");
    return scene;
}

bool OptionScene::init(){
    if (!Scene::init()) {
        return false;
    }
    return true;
}

Widget::ccWidgetClickCallback OptionScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="Back") {
        return CC_CALLBACK_1(OptionScene::Back, this);
    }else if (callBackName=="Control"){
        return CC_CALLBACK_1(OptionScene::Control, this);
    }else if (callBackName=="Sound"){
        return CC_CALLBACK_1(OptionScene::Sound, this);
    }else if (callBackName=="Graphic"){
        return CC_CALLBACK_1(OptionScene::Graphic, this);
    }else if (callBackName=="Ui"){
        return CC_CALLBACK_1(OptionScene::Ui, this);
    }
    
    return nullptr;
}

void OptionScene::Back(cocos2d::Ref *sender){
    if (HistoryUtil::getInstance()->checkSceneHistory("StartGameScene")) {
        auto director = Director::getInstance();
        director->replaceScene(StartGameScene::createScene());
    }else if (HistoryUtil::getInstance()->checkSceneHistory("SettingScene")){
        auto director = Director::getInstance();
        director->replaceScene(SettingScene::createScene());
    }
    
    
}

void OptionScene::Ui(cocos2d::Ref *sender){
    CCLOG("Ui");
}

void OptionScene::Control(cocos2d::Ref *sender){
    CCLOG("Control");
}

void OptionScene::Sound(cocos2d::Ref *sender){
    CCLOG("Sound");
}

void OptionScene::Graphic(cocos2d::Ref *sender){
    CCLOG("Graphic");
}
