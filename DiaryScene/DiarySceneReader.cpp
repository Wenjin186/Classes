//
//  DiarySceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#include "DiarySceneReader.hpp"
#include "DiaryScene.hpp"

static DiarySceneReader *_diarySceneReader = nullptr;

DiarySceneReader *DiarySceneReader::getInstance(){
    if (!_diarySceneReader) {
        _diarySceneReader = new DiarySceneReader();
    }
    
    return _diarySceneReader;
}

void DiarySceneReader::purge(){
    CC_SAFE_DELETE(_diarySceneReader);
}

Node *DiarySceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    DiaryScene *node = DiaryScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
