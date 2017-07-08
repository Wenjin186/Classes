//
//  TestScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/8.
//
//

#include "TestScene.hpp"
#include "StartGameSceneReader.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

Scene* TestScene::createScene()
{
    CSLoader *instance = CSLoader::getInstance();
    instance->registReaderObject("StartGameSceneReader", (ObjectFactory::Instance)StartGameSceneReader::getInstance);
    Scene *node = (Scene *)CSLoader::createNode("test/TestScene.csb");
    return node;
}

bool TestScene::init()
{
    if ( !Scene::init() )
        return false;
    
    return true;
}
