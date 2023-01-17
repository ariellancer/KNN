//
// Created by ariel on 1/15/23.
//
#include "Command.h"
using namespace std;
void setDescription(string str){
    strcpy(this.description,str);
    return;
}
string getDescription(){
    return this.description;
}
void setDio(DefaultIO dio){
    this.dio=dio;
    return;
}
DefaultIO getDio(){
    return this.dio;
}

