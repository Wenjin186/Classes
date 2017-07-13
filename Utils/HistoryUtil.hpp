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

static void setSceneHistory();

using namespace std;
class HistoryUtil{
public:
    static HistoryUtil *getInstance();
    static void purge();
    int checkSceneHistory(string str);
    int checkSceneHistoryWithoutPop(string str);
    void pushSceneHistory(string &str);
private:
    static HistoryUtil *_history;
    //string _sceneHis;
    //stack<string> _sceneHis;
    vector<string> _sceneHis;
};

#endif /* HistoryUtil_hpp */
