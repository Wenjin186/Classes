#include "MyWidgetReader.h"
#include "MyWidget.h"

USING_NS_CC;

static MyWidgetReader* _instanceMyWidgetReader = nullptr;

MyWidgetReader* MyWidgetReader::getInstance()
{
  if (!_instanceMyWidgetReader)
  {
    _instanceMyWidgetReader = new MyWidgetReader();
  }
  return _instanceMyWidgetReader;
}

void MyWidgetReader::purge()
{
  CC_SAFE_DELETE(_instanceMyWidgetReader);
}
Node* MyWidgetReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
  MyWidget* node = MyWidget::create();
  setPropsWithFlatBuffers(node, nodeOptions);
  return node;
} 