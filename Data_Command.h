//
// Created by ariel on 1/18/23.
//
#include "vector"
#include "Vector.h"
#ifndef ASS_41_DATA_COMMAND_H
#define ASS_41_DATA_COMMAND_H


class Data_Command{
private:
int numOfNeighbors=5;
std::string nameOfFunction="AUC";
std::vector<Vector>classified;
std::vector<Vector>unclassified;

bool uploaded= false;
bool didClassify=false;

public:
void setNumOfNeighbors(int k){
    numOfNeighbors=k;
}
void setNameOfFunction(std::string str){
    nameOfFunction=str;
}
std::string getNameOfFunction(){
    return nameOfFunction;
}
int getNumOfNeighbors(){
    return numOfNeighbors;
}
void setClassified(std::vector<Vector>vec){
    classified=vec;
}
    void setUnclassified(std::vector<Vector>vec){
        unclassified=vec;
}
std::vector<Vector>getClassified(){
        return classified;
}

std::vector<Vector>getUnclassified(){
        return unclassified;
}
void updateUploaded(){
    uploaded= true;
}
bool checkUploaded(){
    return uploaded;
}
    void updateClassified(){
        didClassify= true;
    }
    bool checkClassified(){
        return didClassify;
    }


};


#endif //ASS_41_DATA_COMMAND_H
