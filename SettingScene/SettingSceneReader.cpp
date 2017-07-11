//
//  SettingSceneReader.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#include "SettingSceneReader.hpp"
#include "SettingScene.hpp"

static SettingSceneReader *_settingSceneReader = nullptr;

SettingSceneReader *SettingSceneReader::getInstance(){
    
    if (!_settingSceneReader) {
        _settingSceneReader = new SettingSceneReader();
    }
    return _settingSceneReader;
}

void SettingSceneReader::purge(){
    CC_SAFE_DELETE(_settingSceneReader);
}

Node *SettingSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions){
    
    SettingScene *node = SettingScene::create();
    //TestScene *node = TestScene::create();
    setPropsWithFlatBuffers(node, nodeOptions);
    return node;
}
