//
//  ExitSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/10.
//
//

#include "ExitSceneReader.hpp"
#include "ExitScene.hpp"

static ExitSceneReader *_exitSceneReader = nullptr;

ExitSceneReader *ExitSceneReader::getInstance(){
    
    if (!_exitSceneReader) {
        _exitSceneReader = new ExitSceneReader();
    }
    return _exitSceneReader;
}

void ExitSceneReader::purge(){
    CC_SAFE_DELETE(_exitSceneReader);
}

Node *ExitSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    
    ExitScene *node = ExitScene::create();
    //TestScene *node = TestScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
