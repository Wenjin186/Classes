//
//  NewGameScene.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/7.
//
//

#include "NewGameScene.h"
#include "NewGameSceneReader.h"
#include "StartGameScene.h"
#include "WholeFarmScene.hpp"
#include "MxzyStorage.hpp"

extern "C"{
#include "MxzyDatabase.h"
}


Scene *NewGameScene::createScene(){
    CSLoader *instance = CSLoader::getInstance();
    instance->registReaderObject("NewGameSceneReader", (ObjectFactory::Instance)NewGameSceneReader::getInstance);
    Scene *node = (Scene *)instance->createNode("new_game/NewGameScene.csb");
    return node;
}

bool NewGameScene::init()
{
    if ( !Scene::init() )
        return false;

    return true;
}

Widget::ccWidgetClickCallback NewGameScene::onLocateClickCallback(const std::string &callBackName){
    
    if (callBackName=="StartButton") {
        return CC_CALLBACK_1(NewGameScene::StartButton, this);
    }else if (callBackName=="BackButton"){
        return CC_CALLBACK_1(NewGameScene::BackButton, this);
    }
    
    return nullptr;
}

//开始游戏,这里调用后台数据库的函数
void NewGameScene::StartButton(Ref *sender){
    tf = (TextField *)getChildByName("EnterNameTextField");
    string char_str = tf->getString();
    
    int ret = createCharacter(MxzyStorage::getInstance()->getCharacterTable());
    CCLOG("ret=%d\n", ret);
    if (ret == ERROR) {
        //角色满了，无法创建，跳转错误界面
        CCLOG("角色满了，无法创建");
        return;
    }
    
    //MxzyStorage中的CharacterRow已经绑定id为ret，这里不需要释放crow指向的任何内存空间
    int rett = getCharacterRowById(&MxzyStorage::getInstance()->crow, MxzyStorage::getInstance()->getCharacterTable(), ret);
    
    if (rett==ERROR) {
        CCLOG("没有该角色ID的任何信息");
        return;
    }
    
    //设置角色的姓名
    setCharacterName(MxzyStorage::getInstance()->crow, char_str.c_str());
    
    auto director = Director::getInstance();
    director->replaceScene(WholeFarmScene::createScene());
}

void NewGameScene::BackButton(cocos2d::Ref *sender){
    auto director = Director::getInstance();
    director->replaceScene(StartGameScene::createScene());
}
