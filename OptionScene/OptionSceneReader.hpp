//
//  OptionSceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/9.
//
//

#ifndef OptionSceneReader_hpp
#define OptionSceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class OptionSceneReader : public cocostudio::NodeReader{
public:
    static OptionSceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions);
};

#endif /* OptionSceneReader_hpp */
