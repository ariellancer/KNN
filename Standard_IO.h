//
// Created by ariel on 1/17/23.
//
#include "DefaultIO.h"
#include <iostream>

#ifndef ASS_41_STANDARD_IO_H
#define ASS_41_STANDARD_IO_H


class Standard_IO::public DefaultIO {
std::string read() override;
void write(std::string str) override;
};


#endif //ASS_41_STANDARD_IO_H
