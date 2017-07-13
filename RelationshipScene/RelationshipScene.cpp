//
//  RelationshipScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/12.
//
//

#include "RelationshipScene.hpp"
#include "RelationshipSceneReader.hpp"
#include "DiaryScene.hpp"

Scene *RelationshipScene::createScene(){
    CSLoader *loader = CSLoader::getInstance();
    loader->registReaderObject("RelationshipSceneReader", (ObjectFactory::Instance)RelationshipSceneReader::getInstance);
    Scene *scene = (Scene *)loader->createNode("relationship/RelationshipScene.csb");
    return scene;
}

bool RelationshipScene::init(){
    if (!Scene::init()) {
        return false;
    }
    return true;
}

void RelationshipScene::onEnterTransitionDidFinish(){
    Scene::onEnterTransitionDidFinish();
}

Widget::ccWidgetClickCallback RelationshipScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="Animal") {
        return CC_CALLBACK_1(RelationshipScene::Animal, this);
    }else if (callBackName=="Residents"){
        return CC_CALLBACK_1(RelationshipScene::Residents, this);
    }else if (callBackName=="SpecialFriend"){
        return CC_CALLBACK_1(RelationshipScene::SpeicalFriend, this);
    }else if (callBackName=="Employee"){
        return CC_CALLBACK_1(RelationshipScene::Employee, this);
    }else if (callBackName=="Back"){
        return CC_CALLBACK_1(RelationshipScene::Back, this);
    }

    
    return nullptr;
}

void RelationshipScene::Animal(cocos2d::Ref *sender){
    CCLOG("Animal");
}

void RelationshipScene::Residents(cocos2d::Ref *sender){
    CCLOG("Residents");
}

void RelationshipScene::SpeicalFriend(cocos2d::Ref *sender){
    CCLOG("SpecialFriend");
}

void RelationshipScene::Employee(cocos2d::Ref *sender){
    CCLOG("Employee");
}

void RelationshipScene::Back(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(DiaryScene::createScene());
}
