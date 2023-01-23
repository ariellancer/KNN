//
// Created by ariel on 1/17/23.
//

#include "upload.h"
#include "extractFunc.h"
#include <iostream>


using namespace std;

upload::upload(Data_Command *dataCommand) {
    this->dataCommand = dataCommand;
    setDescription("1. upload an unclassified cvs data file\n");
}
void upload:: execute(){
    dio->write("Please upload your local train CVS file.");
    string str= dio->read();
    try {
        vec= initializingTheVectors(str);

    }catch (exception e){
        dio->write("invalid input");
        return;
    }
    dio->write("Upload complete.");
    dataCommand->setClassified(vec);


    dio->write("Please upload your local test CVS file.");
    str=dio->read();
    try {
        vec= initializingTheVectors2(str);

    }catch (exception e){
        dio->write("invalid input");
        return;
    }
    dataCommand->setUnclassified(vec);
    dataCommand->updateUploaded();
}