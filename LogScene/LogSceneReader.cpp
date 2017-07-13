//
//  LogSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#include "LogSceneReader.hpp"
#include "LogScene.hpp"

static LogSceneReader *_logSceneReader = nullptr;

LogSceneReader *LogSceneReader::getInstance(){
    if (!_logSceneReader) {
        _logSceneReader = new LogSceneReader();
    }
    
    return _logSceneReader;
}

void LogSceneReader::purge(){
    CC_SAFE_DELETE(_logSceneReader);
}

Node *LogSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    LogScene *node = LogScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
