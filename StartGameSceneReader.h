//
//  StartGameSceneReader.h
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/7.
//
//

#ifndef StartGameSceneReader_h
#define StartGameSceneReader_h

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class StartGameSceneReader : public cocostudio::NodeReader{
public:
    static StartGameSceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};


#endif /* StartGameSceneReader_h */
