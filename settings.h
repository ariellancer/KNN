//
// Created by ariel on 1/17/23.
//


#include "Command.h"
#include "DefaultIO.h"
#include "Data_Command.h"
#ifndef ASS_41_SECOND_COMMAND_H
#define ASS_41_SECOND_COMMAND_H


class settings::public Command {
private:
    Data_Command dataCommand;
    int numOfNeighbors;
    std::string nameOfFunction;
    void initializeValues(string input);
    bool good(string str);
public:
    void execute() override;
    settings(Data_Command & dataCommand);
  // void setNumOfNeighbors(int k);
  // void setNameOfFunction(std::string str);
  // std::string getNameOfFunction();
  // int getNumOfNeighbors();


};


#endif //ASS_41_SECOND_COMMAND_H
