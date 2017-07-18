//
//  NiuPengSceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/17.
//
//

#ifndef NiuPengSceneReader_hpp
#define NiuPengSceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class NiuPengSceneReader : public cocostudio::NodeReader{
public:
    static NiuPengSceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};


#endif /* NiuPengSceneReader_hpp */
