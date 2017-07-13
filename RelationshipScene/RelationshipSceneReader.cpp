//
//  RelationshipSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#include "RelationshipSceneReader.hpp"
#include "RelationshipScene.hpp"


static RelationshipSceneReader *_relationshipSceneReader = nullptr;

RelationshipSceneReader *RelationshipSceneReader::getInstance(){
    if (!_relationshipSceneReader) {
        _relationshipSceneReader = new RelationshipSceneReader();
    }
    
    return _relationshipSceneReader;
}

void RelationshipSceneReader::purge(){
    CC_SAFE_DELETE(_relationshipSceneReader);
}

Node *RelationshipSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    RelationshipScene *node = RelationshipScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
