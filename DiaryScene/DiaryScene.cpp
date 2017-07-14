//
//  DiaryScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#include "DiaryScene.hpp"
#include "DiarySceneReader.hpp"
#include "WholeFarmScene.hpp"
#include "LogScene.hpp"
#include "InventoryScene.hpp"
#include "MapScene.hpp"
#include "RelationshipScene.hpp"

Scene *DiaryScene::createScene(){
    CSLoader *loader = CSLoader::getInstance();
    loader->registReaderObject("DiarySceneReader", (ObjectFactory::Instance)DiarySceneReader::getInstance);
    Scene *scene = (Scene *)loader->createNode("diary/DiaryScene.csb");
    return scene;
}

bool DiaryScene::init(){
    if (!Scene::init()) {
        return false;
    }
    return true;
}

void DiaryScene::onEnterTransitionDidFinish(){
    Scene::onEnterTransitionDidFinish();
}

Widget::ccWidgetClickCallback DiaryScene::onLocateClickCallback(const std::string &callBackName){

    if (callBackName=="Log") {
        return CC_CALLBACK_1(DiaryScene::Log, this);
    }else if (callBackName=="Map"){
        return CC_CALLBACK_1(DiaryScene::Map, this);
    }else if (callBackName=="Inventory"){
        return CC_CALLBACK_1(DiaryScene::Inventory, this);
    }else if (callBackName=="Relationship"){
        return CC_CALLBACK_1(DiaryScene::Relationship, this);
    }else if (callBackName=="Back"){
        return CC_CALLBACK_1(DiaryScene::Back, this);
    }
    
    return nullptr;
}

void DiaryScene::Log(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(LogScene::createScene());
}

void DiaryScene::Map(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(MapScene::createScene());
}

void DiaryScene::Inventory(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(InventoryScene::createScene());
}

void DiaryScene::Relationship(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(RelationshipScene::createScene());
}

void DiaryScene::Back(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(WholeFarmScene::createScene());
}
