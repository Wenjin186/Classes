//
//  GameUiScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/8.
//
//

#include "WholeFarmScene.hpp"
#include "WholeFarmSceneReader.hpp"
#include "SettingScene.hpp"
#include "DiaryScene.hpp"
#include "NiuPengScene.hpp"
#include "HistoryUtil.hpp"
#include "MxzyStorage.hpp"
#include "SeedSeller.hpp"
#include "SeedStoreScene.hpp"

Scene *WholeFarmScene::createScene(){
    CSLoader *loader = CSLoader::getInstance();
    loader->registReaderObject("WholeFarmSceneReader", (ObjectFactory::Instance)WholeFarmSceneReader::getInstance);
    Scene *scene = (Scene *)loader->createNode("whole_farm/WholeFarmScene.csb");
    scene->scheduleUpdate();
    return scene;
}

bool WholeFarmScene::init(){
    if (!Scene::init()) {
        return false;
    }
    
//  测试数据库
    auto testDb = MxzyStorage::getInstance();
    auto pro_data = testDb->getProtagonistDataById(testDb->getCurrentProId());
    
    
    
    return true;
}

void WholeFarmScene::onEnter(){
    Scene::onEnter();
    
    map = (TMXTiledMap *)getChildByName("WholeFarmMap");
    group = map->getObjectGroup("door");
    niupengDoor = group->getObject("niupengDoor");
    seedStoreDoor = group->getObject("SeedStoreDoor");
    
    button_layer = getChildByName<Layer *>("ButtonLayer");
    button_layer->setAnchorPoint(Vec2(0.5,0.5));
}

void WholeFarmScene::onEnterTransitionDidFinish(){
    Scene::onEnterTransitionDidFinish();
    pro = Protagonist::getInstance();
    pro->setAnchorPoint(Vec2(0.5, 0));
    pro->setPosition(Vec2(500,160));
    this->addChild(pro);
    
    auto seller = SeedSeller::getInstance();
    seller->setPosition(Vec2(720,250));
    addChild(seller);
    
    //
    
    camera = Camera::create();
    camera->setCameraFlag(CameraFlag::USER1);
    addChild(camera);
    setCameraMask(2);
    camera->setAnchorPoint(Vec2(0.5,0.5));
    camera->setPosition(pro->getPosition());
    
    button_layer->setPosition(pro->getPosition());
}

Widget::ccWidgetClickCallback WholeFarmScene::onLocateClickCallback(const std::string &callBackName){

    if (callBackName=="Diary") {
        return CC_CALLBACK_1(WholeFarmScene::Diary, this);
    }else if (callBackName=="Settings"){
        return CC_CALLBACK_1(WholeFarmScene::Settings, this);
    }else if (callBackName=="Trade"){
        return CC_CALLBACK_1(WholeFarmScene::Trade, this);
    }
    return nullptr;
}

void WholeFarmScene::setSceneHistory(){
    auto his = HistoryUtil::getInstance();
    string his_str = "WholeFarmScene";
    his->pushSceneHistory(his_str);
}

void WholeFarmScene::Diary(cocos2d::Ref *sender){
    setSceneHistory();
    auto director = Director::getInstance();
    director->replaceScene(DiaryScene::createScene());
}

void WholeFarmScene::Settings(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(SettingScene::createScene());
}

void WholeFarmScene::Trade(cocos2d::Ref *sender){
    CCLOG("Trade!");
}

void WholeFarmScene::update(float delta){
   // CCLOG("hello world!!");
    judgeNiuPengDoorCollision();
    judgeSeedStoreDoorCollision();
    repositionCamera();
    repositionButtonLayer();
}

void WholeFarmScene::judgeNiuPengDoorCollision(){
    //如果主角和牛棚门碰撞
    Vec2 proPosi = map->convertToNodeSpace(pro->getPosition());
    //CCLOG("%f", proPosi.x);
    if ( ( proPosi.x > niupengDoor.at("x").asFloat()  && proPosi.x < (niupengDoor.at("x").asFloat()+ niupengDoor.at("width").asFloat()) )
        
        &&  ( proPosi.y > niupengDoor.at("y").asFloat() && proPosi.y < (niupengDoor.at("y").asFloat() + niupengDoor.at("height").asFloat())  )
        
        ) {
        auto director = Director::getInstance();
        director->replaceScene(NiuPengScene::createScene());
    }
    
}

void WholeFarmScene::judgeSeedStoreDoorCollision(){
    Vec2 proPosi = map->convertToNodeSpace(pro->getPosition());
    if ( ( proPosi.x > seedStoreDoor.at("x").asFloat()  && proPosi.x < (seedStoreDoor.at("x").asFloat()+ seedStoreDoor.at("width").asFloat()) )
        
        &&  ( proPosi.y > seedStoreDoor.at("y").asFloat() && proPosi.y < (seedStoreDoor.at("y").asFloat() + seedStoreDoor.at("height").asFloat())  )
        
        ){
        
        auto director = Director::getInstance();
        director->replaceScene(SeedStoreScene::createScene());
        
    }
}

void WholeFarmScene::repositionCamera(){
    camera->setPosition(pro->getPosition());
}

void WholeFarmScene::repositionButtonLayer(){
     button_layer->setPosition(pro->getPosition());
}

//测试方法
void WholeFarmScene::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
    //CCLOG("I am in WholeFarmScene");
}
