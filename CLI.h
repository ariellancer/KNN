//
// Created by ariel on 1/17/23.
//
#include "DefaultIO.h"

#ifndef ASS_41_CLI_H
#define ASS_41_CLI_H


class CLI {
private:
    DefaultIO* dio;
public:
    void start();
    CLI(DefaultIO* dio);
};


#endif //ASS_41_CLI_H
