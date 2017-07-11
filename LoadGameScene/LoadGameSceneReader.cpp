//
//  LoadGameSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/10.
//
//

#include "LoadGameSceneReader.hpp"
#include "LoadGameScene.hpp"

static LoadGameSceneReader *_loadGameSceneReader = nullptr;

LoadGameSceneReader *LoadGameSceneReader::getInstance(){
    if (!_loadGameSceneReader) {
        _loadGameSceneReader = new LoadGameSceneReader();
    }
    
    return _loadGameSceneReader;
}

void LoadGameSceneReader::purge(){
    CC_SAFE_DELETE(_loadGameSceneReader);
}

Node *LoadGameSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    LoadGameScene *node = LoadGameScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
