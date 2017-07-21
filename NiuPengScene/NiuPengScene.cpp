//
//  NiuPengScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/16.
//
//

#include "NiuPengScene.hpp"
#include "NiuPengSceneReader.hpp"
#include "HistoryUtil.hpp"
#include "DiaryScene.hpp"
#include "WholeFarmScene.hpp"
#include "Cow.hpp"

//不要修改createScene和init中的任何代码，避免出现问题

Scene* NiuPengScene::createScene()
{
    CSLoader *instance = CSLoader::getInstance();
    instance->registReaderObject("NiuPengSceneReader", (ObjectFactory::Instance)NiuPengSceneReader::getInstance);
    Scene *scene = (Scene *)instance->createNode("niupeng/NiuPengScene.csb");
    scene->scheduleUpdate();
    return scene;
}

//此方法里不要写任何有关添加节点（精灵，图层）的方法，因为这个函数调用的时候，csb文件还没有完全加载
bool NiuPengScene::init()
{
    if ( !Scene::init() )
        return false;
    return true;
}

//当牛棚场景加载进窗口的时候，所有有关新加节点的方法写在这里，比如这个场景中需要添加一头牛
void NiuPengScene::onEnter(){
    Scene::onEnter();
    
    map = (TMXTiledMap *)getChildByName("niupengMap");
    group = map->getObjectGroup("door");
    niupengDoor = group->getObject("niupengDoor");
    
    //切换到牛棚场景的时候，主角一定在牛棚门口，修改下面的代码可以改变主角出现的位置
    Vec2 proPosi(niupengDoor.at("x").asFloat()+niupengDoor.at("width").asFloat()/2, niupengDoor.at("y").asFloat());
    pro = Protagonist::create("character/protagonist.png");
    pro->setAnchorPoint(Vec2(0.5, 0));
    pro->setPosition(proPosi);
    this->addChild(pro);
    
    //再牛棚中添加一头牛
    Cow *cow = Cow::create("animal/cow/cow.png");
    cow->setAnchorPoint(Vec2(0.5, 0));
    cow->setPosition(Vec2(500, 400));
    addChild(cow);
    
}

Widget::ccWidgetClickCallback NiuPengScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="Diary") {
        return CC_CALLBACK_1(NiuPengScene::Diary, this);
    }
    else if (callBackName=="Trade"){
        return CC_CALLBACK_1(NiuPengScene::Trade, this);
    }
    else if (callBackName=="Settings"){
        return CC_CALLBACK_1(NiuPengScene::Settings, this);
    }
    
    return nullptr;
}

void NiuPengScene::setSceneHistory(){
    auto his = HistoryUtil::getInstance();
    string his_str = "NiuPengScene";
    his->pushSceneHistory(his_str);
}

void NiuPengScene::Diary(cocos2d::Ref *sender){
    setSceneHistory();
    auto director = Director::getInstance();
    director->replaceScene(DiaryScene::createScene());
}

void NiuPengScene::Trade(cocos2d::Ref *sender){
    CCLOG("Trade");
}

void NiuPengScene::Settings(cocos2d::Ref *sender){
    CCLOG("Settings");
}

void NiuPengScene::update(float delta){
    Vec2 proPosi = map->convertToNodeSpace(pro->getPosition());
    //CCLOG("%f", proPosi.x);
    if ( ( proPosi.x > niupengDoor.at("x").asFloat()  && proPosi.x < (niupengDoor.at("x").asFloat()+ niupengDoor.at("width").asFloat()) )
        
        &&  ( proPosi.y < niupengDoor.at("y").asFloat()  )
        
        ) {
        auto director = Director::getInstance();
        director->replaceScene(WholeFarmScene::createScene());
    }

}
