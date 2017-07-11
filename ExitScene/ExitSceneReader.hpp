//
//  ExitSceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/10.
//
//

#ifndef ExitSceneReader_hpp
#define ExitSceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class ExitSceneReader : public cocostudio::NodeReader{
public:
    static ExitSceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* ExitSceneReader_hpp */
