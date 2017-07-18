//
//  NiuPengSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/17.
//
//

#include "NiuPengSceneReader.hpp"
#include "NiuPengScene.hpp"

static NiuPengSceneReader *_niuPengSceneReader = nullptr;

NiuPengSceneReader *NiuPengSceneReader::getInstance(){
    
    if (!_niuPengSceneReader) {
        _niuPengSceneReader = new NiuPengSceneReader();
    }
    return _niuPengSceneReader;
}

void NiuPengSceneReader::purge(){
    CC_SAFE_DELETE(_niuPengSceneReader);
}

Node *NiuPengSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    
    NiuPengScene *node = NiuPengScene::create();
    //TestScene *node = TestScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
