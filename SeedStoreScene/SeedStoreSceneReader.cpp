//
//  SeedStoreSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/27.
//
//

#include "SeedStoreSceneReader.hpp"
#include "SeedStoreScene.hpp"

static SeedStoreSceneReader *_seedStoreSceneReader = nullptr;

SeedStoreSceneReader *SeedStoreSceneReader::getInstance(){
    if (!_seedStoreSceneReader) {
        _seedStoreSceneReader = new SeedStoreSceneReader();
    }
    
    return _seedStoreSceneReader;
}

void SeedStoreSceneReader::purge(){
    CC_SAFE_DELETE(_seedStoreSceneReader);
}

Node *SeedStoreSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    SeedStoreScene *node = SeedStoreScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
