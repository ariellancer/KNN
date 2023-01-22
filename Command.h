//
// Created by ariel on 1/15/23.
//
#include "DefaultIO.h"
#include <iostream>

#ifndef ASS_4_CONNAND_H
#define ASS_4_CONNAND_H

class Command{
protected:
    std::string description;
    DefaultIO* dio;
public://:Command
    virtual void execute()=0;
    void setDescription(std::string str);
    void setDio(DefaultIO* dio);
    std::string getDescription();

};


#endif //ASS_4_CONNAND_H
