//
//  SeedStoreSceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/27.
//
//

#ifndef SeedStoreSceneReader_hpp
#define SeedStoreSceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class SeedStoreSceneReader : public cocostudio::NodeReader{
public:
    static SeedStoreSceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions);
};

#endif /* SeedStoreSceneReader_hpp */
