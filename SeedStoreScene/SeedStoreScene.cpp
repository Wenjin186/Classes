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
    
    //测试数据库 spring seed 测试
    auto testDb = MxzyStorage::getInstance()->getGlobalInfoData()->getCppSpring()->getCppSpringSeedTable();
    CCLOG("seed id: %s", testDb->getSeedInfoById(101)->getSeedName().c_str());
    
//    for(int i = 0; i < SPRINGSEEDTABLE_MAX; i++){
//        CCLOG("seed id: %s", testDb->getSeedTable().at(i)->getSeedstagePicpath().c_str());
//    }
    //测试数据库 goodsBag 测试
//    int c1 = MxzyStorage::getInstance()->getGlobalInfoData()->getCppGoodsBagInfo()->getLevelInfoByLevel(1)->getCapacity();
//    
//    int c2 = MxzyStorage::getInstance()->getGlobalInfoData()->getCppGoodsBagInfo()->getLevelInfoByLevel(2)->getCapacity() ;
//    
//    int c3 = MxzyStorage::getInstance()->getGlobalInfoData()->getCppGoodsBagInfo()->getLevelInfoByLevel(3)->getCapacity() ;
//    
//    CCLOG("c1 = %d", c1);
//    CCLOG("c2 = %d", c2);
//    CCLOG("c3 = %d", c3);
    
    return true;
}

void SeedStoreScene::initAllObjects(){
    map = (TMXTiledMap *)getChildByName("SeedStoreMap");
    group = map->getObjectGroup("door");
    InsideDoorLeft = group->getObject("Ldoor");
    seedTable1 = group->getObject("seedtable1");
    seedTable2 = group->getObject("seedtable2");
    seedTable3 = group->getObject("seedtable3");
    seedTable4 = group->getObject("seedtable4");
}

void SeedStoreScene::setProtagonist(){
    Vec2 proPosi(InsideDoorLeft.at("x").asFloat()+InsideDoorLeft.at("width").asFloat()/2, InsideDoorLeft.at("y").asFloat());
    pro = Protagonist::getInstance();
    pro->setAnchorPoint(Vec2(0.5, 0));
    pro->setPosition(proPosi);
    addChild(pro);
}

void SeedStoreScene::setOtherCharacter(){
    seller = SeedSeller::getInstance();
    seller->setAnchorPoint(Vec2(0.5,0));
    seller->setPosition(Vec2(100,100));
    addChild(seller);
}

void SeedStoreScene::setSeedOnTable(){
    auto eggplant = Sprite::create("allgoods_image/eggplant.png");
    //addChild(eggplant);
    eggplant->setAnchorPoint(Vec2(0.5, 0.5));
    Vec2 eggplantPosi = map->convertToNodeSpace(Vec2(seedTable1.at("x").asFloat()+seedTable1.at("width").asFloat()/2, seedTable1.at("y").asFloat() + seedTable1.at("height").asFloat()/2 ));
    eggplant->setPosition(eggplantPosi);
    addChild(eggplant);
}

void SeedStoreScene::onEnter(){
    Scene::onEnter();
    
    initAllObjects();
    setProtagonist();
    setOtherCharacter();
    setSeedOnTable();
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
    
    if ( ( proPosi.x > seedTable1.at("x").asFloat()  && proPosi.x < (seedTable1.at("x").asFloat()+ seedTable1.at("width").asFloat()) )
        
        &&  ( proPosi.y < seedTable1.at("y").asFloat()  )
        
        ) {
        CCLOG("hello world");
    }

}
