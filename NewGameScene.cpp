//
//  NewGameScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/7.
//
//

#include "NewGameScene.h"
#include "NewGameSceneReader.h"


Scene *NewGameScene::createScene(){
    CSLoader *instance = CSLoader::getInstance();
    instance->registReaderObject("NewGameSceneReader", (ObjectFactory::Instance)NewGameSceneReader::getInstance);
    Scene *node = (Scene *)instance->createNode("new_game/NewGameScene.csb");
    return node;
}

bool NewGameScene::init()
{
    if ( !Scene::init() )
        return false;
    
    CCLOG("Hello World!");
    
    return true;
}

Widget::ccWidgetClickCallback NewGameScene::onLocateClickCallback(const std::string &callBackName){

    
    return nullptr;
}
