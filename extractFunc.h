//
// Created by ariel on 12/5/22.
//

#ifndef EX_2MITKADEM_EXTRACTFUNC_H
#define EX_2MITKADEM_EXTRACTFUNC_H

#include "Vector.h"
#include "Distance.h"
/**
 * declaring the functions in extractFunc.
 * @param path
 * @return
 */
std::vector<Vector> initializingTheVectors(std::string input);
std::vector<Vector> initializingTheVectors2(std::string input);
Vector initializationOfVector(char *str, int size);
bool check(char *str);
int getNumberOfNeighbors(char* str);
Distance* getTheMethodOfDistance(char * nameOfFunction);
int getSize(char* arr);
int getSize2(char* arr);
std::vector<char*> getVectorFromUser(char* buffer);
int extractPort(char* port);
bool stop(std::string str);

#endif //EX_2MITKADEM_EXTRACTFUNC_H
