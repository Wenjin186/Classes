//
//  RelationshipSceneReader.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#ifndef RelationshipSceneReader_hpp
#define RelationshipSceneReader_hpp

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

USING_NS_CC;

class RelationshipSceneReader : public cocostudio::NodeReader{
public:
    static RelationshipSceneReader *getInstance();
    static void purge();
    Node *createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions);
};


#endif /* RelationshipSceneReader_hpp */
