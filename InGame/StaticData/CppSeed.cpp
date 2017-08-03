//
//  CppSeed.cpp
//  youxi
//
//  Created by Qi on 2017/8/2.
//
//

#include "CppSeed.hpp"

CppSeed::CppSeed(Seed *seed){
    this->seed = seed;
}

CppSeed::~CppSeed(){

}

void CppSeed::setSeedId(int seedId){
    seed->seed_id = seedId;
}

int CppSeed::getSeedId(){
    return seed->seed_id;
}

void CppSeed::setSeedstageDays(int seedstageDays){
    seed->seedstage_days = seedstageDays;
}

int CppSeed::getSeedstageDays(){
    return seed->seedstage_days;
}

void CppSeed::setSeedstagePicpath(string &seedstagePicpath){
    strcpy(seed->seedstage_picpath,seedstagePicpath.c_str());
}

string &CppSeed::getSeedstagePicpath(){
    seedstagePicpath = string(seed->seedstage_picpath);
    return seedstagePicpath;
}
