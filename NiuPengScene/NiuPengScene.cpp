//
//  NiuPengScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/16.
//
//

#include "NiuPengScene.hpp"
#include "NiuPengSceneReader.hpp"
#include "HistoryUtil.hpp"
#include "DiaryScene.hpp"
#include "WholeFarmScene.hpp"

Scene* NiuPengScene::createScene()
{
    CSLoader *instance = CSLoader::getInstance();
    instance->registReaderObject("NiuPengSceneReader", (ObjectFactory::Instance)NiuPengSceneReader::getInstance);
    Scene *scene = (Scene *)instance->createNode("niupeng/NiuPengScene.csb");
    scene->scheduleUpdate();
    return scene;
}

bool NiuPengScene::init()
{
    if ( !Scene::init() )
        return false;
    
    return true;
}

void NiuPengScene::onEnter(){
    Scene::onEnter();
    
    map = (TMXTiledMap *)getChildByName("niupengMap");
    group = map->getObjectGroup("door");
    niupengDoor = group->getObject("niupengDoor");
    
    Vec2 proPosi(niupengDoor.at("x").asFloat()+niupengDoor.at("width").asFloat()/2, niupengDoor.at("y").asFloat());
    pro = Protagonist::create("character/protagonist.png");
    pro->setAnchorPoint(Vec2(0.5, 0));
    pro->setPosition(proPosi);
    this->addChild(pro);
}

Widget::ccWidgetClickCallback NiuPengScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="Diary") {
        return CC_CALLBACK_1(NiuPengScene::Diary, this);
    }
    else if (callBackName=="Trade"){
        return CC_CALLBACK_1(NiuPengScene::Trade, this);
    }
    else if (callBackName=="Settings"){
        return CC_CALLBACK_1(NiuPengScene::Settings, this);
    }
    
    return nullptr;
}

void NiuPengScene::setSceneHistory(){
    auto his = HistoryUtil::getInstance();
    string his_str = "NiuPengScene";
    his->pushSceneHistory(his_str);
}

void NiuPengScene::Diary(cocos2d::Ref *sender){
    setSceneHistory();
    auto director = Director::getInstance();
    director->replaceScene(DiaryScene::createScene());
}

void NiuPengScene::Trade(cocos2d::Ref *sender){
    CCLOG("Trade");
}

void NiuPengScene::Settings(cocos2d::Ref *sender){
    CCLOG("Settings");
}

void NiuPengScene::update(float delta){
    Vec2 proPosi = map->convertToNodeSpace(pro->getPosition());
    //CCLOG("%f", proPosi.x);
    if ( ( proPosi.x > niupengDoor.at("x").asFloat()  && proPosi.x < (niupengDoor.at("x").asFloat()+ niupengDoor.at("width").asFloat()) )
        
        &&  ( proPosi.y < niupengDoor.at("y").asFloat()  )
        
        ) {
        auto director = Director::getInstance();
        director->replaceScene(WholeFarmScene::createScene());
    }

}
