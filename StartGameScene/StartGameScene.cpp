#include "StartGameScene.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "StartGameSceneReader.h"
#include "NewGameScene.h"
#include "OptionScene.hpp"
#include "LoadGameScene.hpp"
#include "HistoryUtil.hpp"


Scene* StartGameScene::createScene()
{
    CSLoader *instance = CSLoader::getInstance();
    instance->registReaderObject("StartGameSceneReader", (ObjectFactory::Instance)StartGameSceneReader::getInstance);
    Scene *node = (Scene *)instance->createNode("start_game/StartGameScene.csb");
    return node;
}

bool StartGameScene::init()
{
    if ( !Scene::init() )
        return false;
    
    return true;
}

Widget::ccWidgetClickCallback StartGameScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="newGame") {
        return CC_CALLBACK_1(StartGameScene::newGame, this);
    }else if (callBackName=="option"){
        return CC_CALLBACK_1(StartGameScene::option, this);
    }else if (callBackName=="exitGame"){
        return CC_CALLBACK_1(StartGameScene::exitGame, this);
    }else if (callBackName=="loadGame"){
        return CC_CALLBACK_1(StartGameScene::loadGame, this);
    }
    
    return nullptr;
}

void StartGameScene::setSceneHistory(){
    auto his = HistoryUtil::getInstance();
    string his_str = "StartGameScene";
    his->pushSceneHistory(his_str);
}

void StartGameScene::newGame(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(NewGameScene::createScene());
    //setSceneHistory();
}

void StartGameScene::option(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    setSceneHistory();
    director->replaceScene(OptionScene::createScene());
}

void StartGameScene::exitGame(cocos2d::Ref *sender){
    Director::getInstance()->end();
    HistoryUtil::purge();
}

void StartGameScene::loadGame(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    setSceneHistory();
    director->replaceScene(LoadGameScene::createScene());
}
