#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class MyWidgetReader : public cocostudio::NodeReader
{       
public:
  MyWidgetReader() {};
  ~MyWidgetReader() {};

  static MyWidgetReader* getInstance();
  static void purge();
  cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};