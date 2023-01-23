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

settings:: settings(Data_Command *dc){
    this->numOfNeighbors=5;
    this->nameOfFunction="AUC";
    this->dataCommand=dc;
    setDescription("2. algorithm settings\n");
}

bool settings:: good(std::string str){
    char arr[str.length()+1];
    strcpy(arr,str.c_str());
    if(strcmp(arr,"AUC")==0|| strcmp(arr,"MAN")==0||strcmp(arr,"CHB")==0||strcmp(arr,"CAN")==0||
    strcmp(arr,"MIN")==0){
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
            char arr[temp.length()+1];
            strcpy(arr,temp.c_str());
            k=getNumberOfNeighbors(arr);
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
            dio->write("invalid input\n");
            return;
        }
    }
    if(flag==1){
        dio->write("invalid input\n");
        return;
    }
    if(validK== true&&validName== true){
        this->numOfNeighbors=k;
        this->nameOfFunction=name;
        return;
    }
    if(!validK){

        if ((!validName)){
            dio->write("invalid value for K\n");
            dio->write("invalid value for metric\n");
        }
        dio->write("invalid value for K\n");
        return;
    }
    dio->write("invalid value for metric\n");
}

void settings::execute() {
    string str,str1,str2,str3,str4;
    str1="The current KNN parameters are: K = ";
    str2= to_string(this->numOfNeighbors);
    str3=", distance metric = ";
    str4= this->nameOfFunction;
    str=str1+str2+str3+str4;
    dio->write(str);
    string input= dio->read();
    char data[input.length()+1];
    strcpy(data,input.c_str());
    if(strcmp(data,"\n")==0){
        return;
    } else{
        settings::initializeValues(input);
        this->dataCommand->setNameOfFunction(this->nameOfFunction);
        this->dataCommand->setNumOfNeighbors(this->numOfNeighbors);
    }
}