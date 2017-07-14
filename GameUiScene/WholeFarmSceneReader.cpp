//
//  GameUiSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/8.
//
//

#include "GameUiSceneReader.hpp"
#include "GameUiScene.hpp"

static GameUiSceneReader *_gameUiSceneReader = nullptr;

GameUiSceneReader *GameUiSceneReader::getInstance(){
    if (!_gameUiSceneReader) {
        _gameUiSceneReader = new GameUiSceneReader();
    }
    
    return _gameUiSceneReader;
}

void GameUiSceneReader::purge(){
    CC_SAFE_DELETE(_gameUiSceneReader);
}

Node *GameUiSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    GameUiScene *node = GameUiScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
