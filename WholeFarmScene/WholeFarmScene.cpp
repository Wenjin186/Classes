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
    //测试方法
//    keyListener = EventListenerKeyboard::create();
//    keyListener->onKeyPressed = CC_CALLBACK_2(WholeFarmScene::onKeyPressed, this);
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
    return true;
}

void WholeFarmScene::onEnterTransitionDidFinish(){
    pro = Protagonist::create("character/protagonist.png");
    pro->setAnchorPoint(Vec2(0.5, 0));
    pro->setPosition(Vec2(400,0));
    this->addChild(pro);
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

void WholeFarmScene::Diary(cocos2d::Ref *sender){
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
}

//测试方法
void WholeFarmScene::onKeyPressed(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
    //CCLOG("I am in WholeFarmScene");
}
