//
// Created by ariel on 1/15/23.
//
#include "Command.h"
#include "DefaultIO.h"
#include <iostream>

void Command::setDescription(std::string str) {
    this->description=str;
}

void Command::setDio(DefaultIO *dio) {
        this->dio=dio;
}
std::string Command:: getDescription(){
    return this->description;
}

