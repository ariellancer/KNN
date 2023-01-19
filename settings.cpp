//
// Created by ariel on 1/17/23.
//

#include "settings.h"
#include <string.h>
#include "extractFunc.h"
#include "sstream"
#include "Distance.h"

using namespace std;
//void settings::setNumOfNeighbors(int k) {
//    this->numOfNeighbors=k;
//    return;
//}
//
//void settings::setNameOfFunction(int str) {
//    this->nameOfFunction=str;
//}
//string settings::getNameOfFunction() {
//    return this->nameOfFunction;
//}
//
//int settings::getNumOfNeighbors() {
//    return this->numOfNeighbors;
//}

settings:: settings(Data_Command &dc){
    this->numOfNeighbors=5;
    this->nameOfFunction="AUC";
    this->dataCommand=dc;
    setDescription("2. algorithm settings\n");
}

bool settings:: good(string str){
    if(strcmp(str,"AUC")==0|| strcmp(str,"MAN")==0||strcmp(str,"CHB")==0||strcmp(str,"CAN")==0||
    strcmp(nameOfFunction,"MIN")==0){
        return true;
    }
    return false;
}

void settings::initializeValues(std::string input) {
    int flag=0;
    int k;
    bool validK= true,validName= true;
    string temp,name;
    stringstream s(input);
    while (getline(s,temp,' ')){
        if (flag==0){
            k=getNumberOfNeighbors(temp);
            if(k==-1){
                validK= false;
            }
            flag++;
            continue;
        }
        if(flag==1){
            if(!good(temp)){
                validName= false;
                continue;
            }
            name= temp;
            flag++;
            continue;
        }else{
            dio.write("invalid input\n");
            return;
        }
    }
    if(validK== true&&validName== true){
        numOfNeighbors=k;
        nameOfFunction=name;
        return;
    }
    if(!validK){
        dio.write("invalid value for K\n");
        if ((!validName)){
            dio.write("invalid value for metric\n");
        }
        return;
    }
    dio.write("invalid value for metric\n");
}

void settings::execute() {
    string str= "The current KNN parameters are: K = "+ this->numOfNeighbors+", distance metric = " +this->nameOfFunction;
    dio->write(str);
    string input= dio->read();
    if(strcmp(input,"\n")){
        return;
    } else{
        settings::initializeValues(input);
        this->dataCommand.setNameOfFunction(this->nameOfFunction);
        this->dataCommand.setNumOfNeighbors(this->numOfNeighbors);
    }
}