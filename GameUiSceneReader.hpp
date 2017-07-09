//
//  GameUiSceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/8.
//
//

#ifndef GameUiSceneReader_hpp
#define GameUiSceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class GameUiSceneReader : public cocostudio::NodeReader{
public:
    static GameUiSceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions);
};

#endif /* GameUiSceneReader_hpp */
