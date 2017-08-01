//
//  SeedStoreScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/27.
//
//

#include "SeedStoreScene.hpp"
#include "SeedStoreSceneReader.hpp"
#include "WholeFarmScene.hpp"
#include "MxzyStorage.hpp"

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

void SeedStoreScene::onEnter(){
    Scene::onEnter();
    
    map = (TMXTiledMap *)getChildByName("SeedStoreMap");
    group = map->getObjectGroup("door");
    InsideDoorLeft = group->getObject("Ldoor");
    //table1 = group->getObject("table1");
    
    Vec2 proPosi(InsideDoorLeft.at("x").asFloat()+InsideDoorLeft.at("width").asFloat()/2, InsideDoorLeft.at("y").asFloat());
    pro = Protagonist::getInstance();
    pro->setAnchorPoint(Vec2(0.5, 0));
    pro->setPosition(proPosi);
    addChild(pro);
    
    seller = SeedSeller::getInstance();
    seller->setAnchorPoint(Vec2(0.5,0));
    seller->setPosition(Vec2(100,100));
    addChild(seller);
    
    auto storage = MxzyStorage::getInstance();
    auto pro_data = storage->getProtagonistDataById(storage->getCurrentProId());
    auto bag = pro_data->getGoodsBag();
    //bag->get
    CCLOG("bag level = %d", bag->getCurrentLevel());
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
    judgeLdoorCollision();
    //judgeTable1Collision();
}

void SeedStoreScene::judgeLdoorCollision(){
    Vec2 proPosi = map->convertToNodeSpace(pro->getPosition());
    //CCLOG("%f", proPosi.x);
    if ( ( proPosi.x > InsideDoorLeft.at("x").asFloat()  && proPosi.x < (InsideDoorLeft.at("x").asFloat()+ InsideDoorLeft.at("width").asFloat()) )
        
        &&  ( proPosi.y < InsideDoorLeft.at("y").asFloat()  )
        
        ) {
        auto director = Director::getInstance();
        director->replaceScene(WholeFarmScene::createScene());
    }
}

void SeedStoreScene::judgeTable1Collision(){
    //转换坐标
    Vec2 proPosi = map->convertToNodeSpace(pro->getPosition());
    
    if ( ( proPosi.x > table1.at("x").asFloat()  && proPosi.x < (table1.at("x").asFloat()+ table1.at("width").asFloat()) )
        
        &&  ( proPosi.y < table1.at("y").asFloat()  )
        
        ) {
        CCLOG("hello world");
    }

}
