//
//  InventorySceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#ifndef InventorySceneReader_hpp
#define InventorySceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class InventorySceneReader : public cocostudio::NodeReader{
public:
    static InventorySceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions);
};
#endif /* InventorySceneReader_hpp */
