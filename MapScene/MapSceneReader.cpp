//
//  MapSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#include "MapSceneReader.hpp"
#include "MapScene.hpp"


static MapSceneReader *_mapSceneReader = nullptr;

MapSceneReader *MapSceneReader::getInstance(){
    if (!_mapSceneReader) {
        _mapSceneReader = new MapSceneReader();
    }
    
    return _mapSceneReader;
}

void MapSceneReader::purge(){
    CC_SAFE_DELETE(_mapSceneReader);
}

Node *MapSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    MapScene *node = MapScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
