//
//  HistoryUtil.hpp
//  cocos3.10-mxzy
//
//  Created by Wenjin Zhang on 2017/7/11.
//
//

#ifndef HistoryUtil_hpp
#define HistoryUtil_hpp

#include "cocos2d.h"

USING_NS_CC;

using namespace std;
class HistoryUtil{
public:
    static HistoryUtil *getInstance();
    static void purge();
    string getSceneHistory();
    void setSceneHistory(string &str);
private:
    static HistoryUtil *_history;
    //string _sceneHis;
    //stack<string> _sceneHis;
    Vector<string> _sceneHis;
};

#endif /* HistoryUtil_hpp */
