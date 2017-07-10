//
//  NewGameSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/7.
//
//

#include "NewGameScene.h"
#include "NewGameSceneReader.h"

static NewGameSceneReader *_newGameScenereader = nullptr;

NewGameSceneReader *NewGameSceneReader::getInstance(){
    
    if (!_newGameScenereader) {
        _newGameScenereader = new NewGameSceneReader();
    }
    return _newGameScenereader;
}

void NewGameSceneReader::purge(){
    CC_SAFE_DELETE(_newGameScenereader);
}

Node *NewGameSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    
    NewGameScene *node = NewGameScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
