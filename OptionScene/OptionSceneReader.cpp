//
//  OptionSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/9.
//
//

#include "OptionScene.hpp"
#include "OptionSceneReader.hpp"

static OptionSceneReader *_optionSceneReader = nullptr;

OptionSceneReader *OptionSceneReader::getInstance(){
    if (!_optionSceneReader) {
        _optionSceneReader = new OptionSceneReader();
    }
    
    return _optionSceneReader;
}

void OptionSceneReader::purge(){
    CC_SAFE_DELETE(_optionSceneReader);
}

Node *OptionSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    OptionScene *node = OptionScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
