//
//  DiarySceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#ifndef DiarySceneReader_hpp
#define DiarySceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class DiarySceneReader : public cocostudio::NodeReader{
public:
    static DiarySceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions);
};


#endif /* DiarySceneReader_hpp */
