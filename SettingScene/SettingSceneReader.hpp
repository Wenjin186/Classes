//
//  SettingSceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#ifndef SettingSceneReader_hpp
#define SettingSceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class SettingSceneReader : public cocostudio::NodeReader{
public:
    static SettingSceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* SettingSceneReader_hpp */
