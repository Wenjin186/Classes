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

void CppSeed::setSeedName(string &seedName){
    strcpy(seed->seed_name,seedName.c_str());
}

string &CppSeed::getSeedName(){
    seedName = string(seed->seed_name);
    return seedName;
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

void CppSeed::setStage1Days(int stage1Days){
    seed->stage1_days = stage1Days;
}

int CppSeed::getStage1Days(){
    return seed->stage1_days;
}

void CppSeed::setStage1Picpath(string &stage1Picpath){
    strcpy(seed->stage1_picpath,stage1Picpath.c_str());
}

string &CppSeed::getStage1Picpath(){
    stage1Picpath = string(seed->stage1_picpath);
    return stage1Picpath;
}

void CppSeed::setStage2Days(int stage2Days){
    seed->stage2_days = stage2Days;
}

int CppSeed::getStage2Days(){
    return seed->stage2_days;
}

void CppSeed::setStage2Picpath(string &stage2Picpath){
    strcpy(seed->stage2_picpath,stage2Picpath.c_str());
}

string &CppSeed::getStage2Picpath(){
    stage2Picpath = string(seed->stage2_picpath);
    return stage2Picpath;
}

void CppSeed::setStage3Days(int stage3Days){
    seed->stage3_days = stage3Days;
}

int CppSeed::getStage3Days(){
    return seed->stage3_days;
}

void CppSeed::setStage3Picpath(string &stage3Picpath){
    strcpy(seed->stage3_picpath,stage3Picpath.c_str());
}

string &CppSeed::getStage3Picpath(){
    stage3Picpath = string(seed->stage3_picpath);
    return stage3Picpath;
}

void CppSeed::setReturnStage(int returnStage){
    seed->returnStage = returnStage;
}

int CppSeed::getReturnStage(){
    return seed->returnStage;
}

void CppSeed::setSeedBasicOutput(int seedBasicOutput){
    seed->seed_basic_output = seedBasicOutput;
}

int CppSeed::getSeedBasicOutput(){
    return seed->seed_basic_output;
}

void CppSeed::setSeedHighOutput(int seedHighOutput){
    seed->seed_high_output = seedHighOutput;
}

int CppSeed::getSeedHighOutput(){
    return seed->seed_high_output;
}

void CppSeed::setDeathdays(int deathdays){
    seed->deathdays = deathdays;
}

int CppSeed::getDeathdays(){
    return seed->deathdays;
}

void CppSeed::setGoodsId(int goodsId){
    seed->goods_id = goodsId;
}

int CppSeed::getGoodsId(){
    return seed->goods_id;
}
