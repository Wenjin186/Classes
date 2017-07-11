//
//  LoadGameSceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/10.
//
//

#ifndef LoadGameSceneReader_hpp
#define LoadGameSceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class LoadGameSceneReader : public cocostudio::NodeReader{
public:
    static LoadGameSceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions);
};

#endif /* LoadGameSceneReader_hpp */
