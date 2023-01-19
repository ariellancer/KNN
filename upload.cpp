//
// Created by ariel on 1/17/23.
//

#include "upload.h"
#include "extractFunc.h"
#include <iostream>


using namespace std;

upload::upload(Data_Command &dataCommand) {
    this->dataCommand = dataCommand;
    setDescription("1. upload an unclassified cvs data file\n");
}
void upload:: execute(){
    dio->write("Please upload your local train CVS file.\n");
    string str= dio->read();
    try {
        vec= initializingTheVectors(str);

    }catch (exception e){
        dio->write("invalid input\n");
        return;
    }
    dio->write("Upload complete.\n");
    dataCommand.getClassified(vec);



    dio->write("Please upload your local test CVS file.\n");
    str=dio->read();
    try {
        vec= initializingTheVectors(str);

    }catch (exception e){
        dio->write("invalid input\n");
        return;
    }
    dataCommand.getUnclassified(vec);
    dataCommand.updateUploaded();
}