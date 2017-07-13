//
//  LogScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#include "LogScene.hpp"
#include "LogSceneReader.hpp"
#include "DiaryScene.hpp"

Scene *LogScene::createScene(){
    CSLoader *loader = CSLoader::getInstance();
    loader->registReaderObject("LogSceneReader", (ObjectFactory::Instance)LogSceneReader::getInstance);
    Scene *scene = (Scene *)loader->createNode("log/LogScene.csb");
    return scene;
}

bool LogScene::init(){
    if (!Scene::init()) {
        return false;
    }
    return true;
}

void LogScene::onEnterTransitionDidFinish(){
    Scene::onEnterTransitionDidFinish();
}

Widget::ccWidgetClickCallback LogScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="Asset") {
        return CC_CALLBACK_1(LogScene::Asset, this);
    }else if (callBackName=="Info"){
        return CC_CALLBACK_1(LogScene::Info, this);
    }else if (callBackName=="Objective"){
        return CC_CALLBACK_1(LogScene::Objective, this);
    }else if (callBackName=="Trade"){
        return CC_CALLBACK_1(LogScene::Trade, this);
    }else if (callBackName=="Back"){
        return CC_CALLBACK_1(LogScene::Back, this);
    }
    
    return nullptr;
}

void LogScene::Asset(cocos2d::Ref *sender){
    CCLOG("Asset");
}

void LogScene::Info(cocos2d::Ref *sender){
    CCLOG("Info");
}

void LogScene::Objective(cocos2d::Ref *sender){
    CCLOG("Objective");
}

void LogScene::Trade(cocos2d::Ref *sender){
    CCLOG("Trade");
}

void LogScene::Back(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(DiaryScene::createScene());
}
