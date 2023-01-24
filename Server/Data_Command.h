//
// Created by ariel on 1/18/23.
//
#include "vector"
#include "Vector.h"
#ifndef ASS_41_DATA_COMMAND_H
#define ASS_41_DATA_COMMAND_H


class Data_Command{
private:
int numOfNeighbors;
std::string nameOfFunction;
std::vector<Vector>classified;
std::vector<Vector>unclassified;

bool uploaded= false;
bool didClassify=false;

public:
void setNumOfNeighbors(int k);
void setNameOfFunction(std::string str);
std::string getNameOfFunction();
int getNumOfNeighbors();
void setClassified(std::vector<Vector>vec);
void setUnclassified(std::vector<Vector>vec);
std::vector<Vector>getClassified();
std::vector<Vector>getUnclassified();
void updateUploaded();
bool checkUploaded();
void updateClassified();
bool checkClassified();
Data_Command();
};


#endif //ASS_41_DATA_COMMAND_H
