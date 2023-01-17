//
// Created by ariel on 1/15/23.
//
#include "DefaultIO.h"
#ifndef ASS_4_CONNAND_H
#define ASS_4_CONNAND_H

class Command{
private:
    std::string description;
    DefaultIO:: dio;
public://:Command
    virtual void execute()=0;
    void setDescription(string str);
    void setDio(DefaultIO dio);
    DefaultIO getDio();
    std::string getDescription();

};


#endif //ASS_4_CONNAND_H
