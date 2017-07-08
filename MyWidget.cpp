#include "MyWidget.h"
#include "ui/UIText.h"
USING_NS_CC;
using namespace std;
using namespace cocos2d::ui;

MyWidget::MyWidget(){}

Widget::ccWidgetTouchCallback MyWidget::onLocateTouchCallback(const string &callBackName)
{
  if (callBackName == "onTouch")
  {
    return CC_CALLBACK_2(MyWidget::onTouch, this);
  }
  return nullptr;
}

Widget::ccWidgetClickCallback MyWidget::onLocateClickCallback(const string &callBackName)
{
  if (callBackName == "clickScreen")
  {
    return CC_CALLBACK_1(MyWidget::clickScreen, this);
  }
  return nullptr;
}

Widget::ccWidgetEventCallback MyWidget::onLocateEventCallback(const string &callBackName)
{
  if (callBackName == "onEvent")
  {
    return CC_CALLBACK_2(MyWidget::onEvent, this);
  }
  return nullptr;
}

void MyWidget::onEvent(cocos2d::Ref* sender, int eventType)
{
    CCLOG("onEvent");
}
void MyWidget::onTouch(cocos2d::Ref* object, cocos2d::ui::Widget::TouchEventType type)
{
  CCLOG("onTouch");
}


//按钮回调方法在这里修改，点击屏幕之后切换到选择角色界面
void MyWidget::clickScreen(cocos2d::Ref* sender)
{
  CCLOG("Click Screen!!");
    //auto director = Director::getInstance();
    //director->replaceScene(ChooseCharacterScene::createScene());
}
