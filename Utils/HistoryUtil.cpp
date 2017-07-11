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

string HistoryUtil::getSceneHistory(){
    string temp = _sceneHis.back();
    _sceneHis.popBack();
    return temp;
}

void HistoryUtil::setSceneHistory(string &str){
    this->_sceneHis.pushBack(str);
}
