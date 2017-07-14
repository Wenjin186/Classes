//
//  GameUiSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/8.
//
//

#include "WholeFarmSceneReader.hpp"
#include "WholeFarmScene.hpp"

static WholeFarmSceneReader *_wholeFarmSceneReader = nullptr;

WholeFarmSceneReader *WholeFarmSceneReader::getInstance(){
    if (!_wholeFarmSceneReader) {
        _wholeFarmSceneReader = new WholeFarmSceneReader();
    }
    
    return _wholeFarmSceneReader;
}

void WholeFarmSceneReader::purge(){
    CC_SAFE_DELETE(_wholeFarmSceneReader);
}

Node *WholeFarmSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    WholeFarmScene *node = WholeFarmScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
