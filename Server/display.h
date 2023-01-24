//
// Created by ariel on 1/17/23.
//
#include "Command.h"
#include "DefaultIO.h"
#include "Data_Command.h"
#ifndef ASS_41_FORTH_COMMAND_H
#define ASS_41_FORTH_COMMAND_H


class display: public Command {
private:
    Data_Command *dataCommand;
public:
    void execute() override;
    display(Data_Command *dc);

};


#endif //ASS_41_FORTH_COMMAND_H
