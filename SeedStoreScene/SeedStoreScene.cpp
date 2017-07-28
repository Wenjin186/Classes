//
//  SeedStoreScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/27.
//
//

#include "SeedStoreScene.hpp"
#include "SeedStoreSceneReader.hpp"

Scene *SeedStoreScene::createScene(){
    CSLoader *loader = CSLoader::getInstance();
    loader->registReaderObject("SeedStoreSceneReader", (ObjectFactory::Instance)SeedStoreSceneReader::getInstance);
    Scene *scene = (Scene *)loader->createNode("seed_store/SeedStoreScene.csb");
    return scene;
}

bool SeedStoreScene::init(){
    if (!Scene::init()) {
        return false;
    }
    return true;
}

void SeedStoreScene::onEnterTransitionDidFinish(){
    Scene::onEnterTransitionDidFinish();
}

Widget::ccWidgetClickCallback SeedStoreScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="Settings") {
        return CC_CALLBACK_1(SeedStoreScene::Settings, this);
    }else if (callBackName=="Diary"){
        return CC_CALLBACK_1(SeedStoreScene::Diary, this);
    }else if (callBackName=="Trade"){
        return CC_CALLBACK_1(SeedStoreScene::Trade, this);
    }
    return nullptr;
}

void SeedStoreScene::Settings(cocos2d::Ref *sender){
    
}

void SeedStoreScene::Diary(cocos2d::Ref *sender){
    
}

void SeedStoreScene::Trade(cocos2d::Ref *sender){
    
}

void SeedStoreScene::update(float delta){
    
}


