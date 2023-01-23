//
// Created by ariel on 1/18/23.
//

#include "Data_Command.h"

using namespace std;
Data_Command:: Data_Command(){
    this->numOfNeighbors=5;
    this->nameOfFunction="AUC";
}

void Data_Command::setNumOfNeighbors(int k) {
    this->numOfNeighbors=k;
}

void Data_Command::setNameOfFunction(std::string str) {
    this->nameOfFunction=str;
}
string Data_Command::getNameOfFunction() {
    return nameOfFunction;
}
int Data_Command::getNumOfNeighbors() {
    return numOfNeighbors;
}
void Data_Command::setClassified(std::vector <Vector> vec) {
    this->classified=vec;
}
void Data_Command::setUnclassified(std::vector <Vector> vec) {
    this->unclassified=vec;
}
std::vector<Vector> Data_Command::getClassified() {
    return classified;
}

std::vector <Vector> Data_Command::getUnclassified() {
    return unclassified;
}

void Data_Command::updateUploaded() {
    this->uploaded= true;
}

bool Data_Command::checkUploaded() {
    return uploaded;
}

void Data_Command::updateClassified() {
    this->didClassify= true;
}

bool Data_Command::checkClassified() {
    return didClassify;
}