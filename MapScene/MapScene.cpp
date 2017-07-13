//
//  MapScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#include "MapScene.hpp"
#include "MapSceneReader.hpp"
#include "DiaryScene.hpp"

Scene *MapScene::createScene(){
    CSLoader *loader = CSLoader::getInstance();
    loader->registReaderObject("MapSceneReader", (ObjectFactory::Instance)MapSceneReader::getInstance);
    Scene *scene = (Scene *)loader->createNode("map/MapScene.csb");
    return scene;
}

bool MapScene::init(){
    if (!Scene::init()) {
        return false;
    }
    return true;
}

void MapScene::onEnterTransitionDidFinish(){
    Scene::onEnterTransitionDidFinish();
}

Widget::ccWidgetClickCallback MapScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="WorldMap") {
        return CC_CALLBACK_1(MapScene::WorldMap, this);
    }else if (callBackName=="SeaVoyage"){
        return CC_CALLBACK_1(MapScene::SeaVoyage, this);
    }else if (callBackName=="IslandMap"){
        return CC_CALLBACK_1(MapScene::IslandMap, this);
    }else if (callBackName=="Back"){
        return CC_CALLBACK_1(MapScene::Back, this);
    }
    
    return nullptr;
}

void MapScene::WorldMap(cocos2d::Ref *sender){
    CCLOG("WorldMap");
}

void MapScene::SeaVoyage(cocos2d::Ref *sender){
    CCLOG("SeaVoyage");
}

void MapScene::IslandMap(cocos2d::Ref *sender){
    CCLOG("IslandMap");
}

void MapScene::Back(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(DiaryScene::createScene());
}
