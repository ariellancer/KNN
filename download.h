//
// Created by ariel on 1/17/23.
//
#include "Command.h"
#include "Data_Command.h"
#include "DefaultIO.h"
#ifndef ASS_41_FIFTH_COMMAND_H
#define ASS_41_FIFTH_COMMAND_H


class download:: public Command {
private:
    Data_Command dataCommand;
public:
    void execute() override;
    download(Data_Command &dc);
};


#endif //ASS_41_FIFTH_COMMAND_H
