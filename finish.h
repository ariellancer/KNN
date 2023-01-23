//
// Created by ariel on 1/17/23.
//
#include "Command.h"
#include "DefaultIO.h"
#ifndef ASS_41_EXIT_H
#define ASS_41_EXIT_H


class finish: public Command {
public:
    void execute()override;
    finish();
};


#endif //ASS_41_EXIT_H
