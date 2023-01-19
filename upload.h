//
// Created by ariel on 1/17/23.
//
#include "Command.h"
#include "DefaultIO.h"
#include <iostream>
#include "Data_Command.h"
#include "vector"
#include "Vector.h"

#ifndef ASS_41_FIRST_COMMAND_H
#define ASS_41_FIRST_COMMAND_H

/**
 * class of first_command.
 */
class upload: public Command{
private:
    Data_Command dataCommand;
    std::vector<Vector> vec;
public:
    void execute() override;
    upload(Data_Command &dc);

};


#endif //ASS_41_FIRST_COMMAND_H
