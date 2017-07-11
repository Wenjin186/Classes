//
//  SettingScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#include "SettingScene.hpp"
#include "SettingSceneReader.hpp"
#include "GameUiScene.hpp"
#include "ExitScene.hpp"
#include "LoadGameScene.hpp"

Scene* SettingScene::createScene()
{
    CSLoader *instance = CSLoader::getInstance();
    instance->registReaderObject("SettingSceneReader", (ObjectFactory::Instance)SettingSceneReader::getInstance);
    Scene *node = (Scene *)instance->createNode("setting/SettingScene.csb");
    return node;
}

bool SettingScene::init()
{
    if ( !Scene::init() )
        return false;
    
    return true;
}

Widget::ccWidgetClickCallback SettingScene::onLocateClickCallback(const std::string &callBackName){

    if (callBackName=="Save") {
        return CC_CALLBACK_1(SettingScene::Save, this);
    }else if (callBackName=="Option"){
        return CC_CALLBACK_1(SettingScene::Option, this);
    }else if (callBackName=="Load"){
        return CC_CALLBACK_1(SettingScene::Load, this);
    }else if (callBackName=="Exit"){
        return CC_CALLBACK_1(SettingScene::Exit, this);
    }else if (callBackName=="Back"){
        return CC_CALLBACK_1(SettingScene::Back, this);
    }
    
    
    return nullptr;
}

void SettingScene::Save(cocos2d::Ref *sender){
    CCLOG("Save");
}

void SettingScene::Option(cocos2d::Ref *sender){
    CCLOG("Option");
}

void SettingScene::Load(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(LoadGameScene::createScene());
}

void SettingScene::Exit(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(ExitScene::createScene());
}

void SettingScene::Back(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(GameUiScene::createScene());
}
