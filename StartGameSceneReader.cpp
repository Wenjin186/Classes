//
//  StartGameSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/7.
//
//
#include "StartGameScene.h"
#include "StartGameSceneReader.h"
#include "TestScene.hpp"


static StartGameSceneReader *_reader = nullptr;

StartGameSceneReader *StartGameSceneReader::getInstance(){
    
    if (!_reader) {
        _reader = new StartGameSceneReader();
    }
    return _reader;
}

void StartGameSceneReader::purge(){
    CC_SAFE_DELETE(_reader);
}

Node *StartGameSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    
    StartGameScene *node = StartGameScene::create();
    //TestScene *node = TestScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
