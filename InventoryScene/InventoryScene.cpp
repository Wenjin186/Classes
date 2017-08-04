//
//  InventoryScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#include "InventoryScene.hpp"
#include "InventorySceneReader.hpp"
#include "DiaryScene.hpp"

Scene *InventoryScene::createScene(){
    CSLoader *loader = CSLoader::getInstance();
    loader->registReaderObject("InventorySceneReader", (ObjectFactory::Instance)InventorySceneReader::getInstance);
    Scene *scene = (Scene *)loader->createNode("inventory/InventoryScene.csb");
    return scene;
}

bool InventoryScene::init(){
    if (!Scene::init()) {
        return false;
    }
    return true;
}

void InventoryScene::initGoodsBagLayer(){
    goodsBag_layer = (Layer *)getChildByName("GoodsBagLayer");
    goodsBag_layer->setVisible(false);
    
    goodsBagSprite = GoodsBagSprite::create();
    goodsBagSprite->setAnchorPoint(Vec2(0,0));
    goodsBag_layer->addChild(goodsBagSprite);
}

void InventoryScene::onEnterTransitionDidFinish(){
    Scene::onEnterTransitionDidFinish();
    
    initGoodsBagLayer();
}

Widget::ccWidgetClickCallback InventoryScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="Craft") {
        return CC_CALLBACK_1(InventoryScene::Craft, this);
    }else if (callBackName=="Items"){
        return CC_CALLBACK_1(InventoryScene::Items, this);
    }else if (callBackName=="Tool"){
        return CC_CALLBACK_1(InventoryScene::Tool, this);
    }else if (callBackName=="Back"){
        return CC_CALLBACK_1(InventoryScene::Back, this);
    }
    
    return nullptr;
}

void InventoryScene::Craft(cocos2d::Ref *sender){
    CCLOG("Craft");
}

void InventoryScene::Items(cocos2d::Ref *sender){
    goodsBag_layer->setVisible(true);
}

void InventoryScene::Tool(cocos2d::Ref *sender){
    CCLOG("Tool");
}

void InventoryScene::Back(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(DiaryScene::createScene());
}
