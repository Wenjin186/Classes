//
//  NewGameSceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/7.
//
//

#ifndef NewGameSceneReader_hpp
#define NewGameSceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class NewGameSceneReader : public cocostudio::NodeReader{
public:
    static NewGameSceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif /* NewGameSceneReader_hpp */
