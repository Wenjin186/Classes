//
//  CppSeed.hpp
//  youxi
//
//  Created by Qi on 2017/8/2.
//
//

#ifndef CppSeed_hpp
#define CppSeed_hpp

#include "cocos2d.h"

using namespace std;

extern "C"{
#include "MxzyDatabase.h"
}

class CppSeed{
public:
    CppSeed(Seed *seed);
    ~CppSeed();
    void setSeedId(int seedId);
    int getSeedId();
    
    void setSeedName(string &seedName);
    string &getSeedName();
    
    void setSeedstageDays(int seedstageDays);
    int getSeedstageDays();
    
    void setSeedstagePicpath(string &seedstagePicpath);
    string &getSeedstagePicpath();
    
    void setStage1Days(int stage1Days);
    int getStage1Days();
    
    void setStage1Picpath(string &stage1Picpath);
    string &getStage1Picpath();
    
    void setStage2Days(int stage2Days);
    int getStage2Days();
    
    void setStage2Picpath(string &stage2Picpath);
    string &getStage2Picpath();

    void setStage3Days(int stage3Days);
    int getStage3Days();
    
    void setStage3Picpath(string &stage3Picpath);
    string &getStage3Picpath();
    
    void setReturnStage(int returnStage);
    int getReturnStage();
    
    void setSeedBasicOutput(int seedBasicOutput);
    int getSeedBasicOutput();
    
    void setSeedHighOutput(int seedHighOutput);
    int getSeedHighOutput();
    
    void setDeathdays(int deathdays);
    int getDeathdays();

    void setGoodsId(int goodsId);
    int getGoodsId();
    
private:
    Seed *seed;
    string seedName;
    string seedstagePicpath;
    string stage1Picpath;
    string stage2Picpath;
    string stage3Picpath;
    
};

#endif /* CppSeed_hpp */
