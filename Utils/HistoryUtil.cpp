//
//  HistoryUtil.cpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#include "HistoryUtil.hpp"

HistoryUtil *HistoryUtil::_history = nullptr;

HistoryUtil *HistoryUtil::getInstance(){
    
    if (!_history) {
        _history = new HistoryUtil();
        return _history;
    }
    
    return _history;
}

void HistoryUtil::purge(){
    CC_SAFE_FREE(HistoryUtil::_history);
}

int HistoryUtil::checkSceneHistory(string str){
    string temp = _sceneHis.back();
    if (temp == str) {
        _sceneHis.pop_back();
        return 1;
    }else
        return 0;
}

int HistoryUtil::checkSceneHistoryWithoutPop(string str){
    
    string temp = _sceneHis.back();
    if (temp==str) {
        return 1;
    }else
        return 0;
}

void HistoryUtil::pushSceneHistory(string &str){
    this->_sceneHis.push_back(str);
}
