#include "StartGameScene.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "StartGameSceneReader.h"
#include "NewGameScene.h"


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
    }
    
    return nullptr;
}

void StartGameScene::newGame(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(NewGameScene::createScene());
}

