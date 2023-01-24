//
// Created by ariel on 1/15/23.
//
#include <iostream>


#ifndef ASS_4_DEFAULTIO_H
#define ASS_4_DEFAULTIO_H

class DefaultIO{
public:
    virtual std::string read()=0;
    virtual void write(std::string str)=0;
    virtual void Close()=0;
};


#endif //ASS_4_DEFAULTIO_H
