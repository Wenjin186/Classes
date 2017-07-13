//
//  InventorySceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#include "InventorySceneReader.hpp"
#include "InventoryScene.hpp"

static InventorySceneReader *_inventorySceneReader = nullptr;

InventorySceneReader *InventorySceneReader::getInstance(){
    if (!_inventorySceneReader) {
        _inventorySceneReader = new InventorySceneReader();
    }
    
    return _inventorySceneReader;
}

void InventorySceneReader::purge(){
    CC_SAFE_DELETE(_inventorySceneReader);
}

Node *InventorySceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    InventoryScene *node = InventoryScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
