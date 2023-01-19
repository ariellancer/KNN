//
// Created by ariel on 1/17/23.
//

#include "display.h"
#include "string.h"
#include "iostream"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void display: display(Data_Command &dc){
dataCommand=dc;
setDescription("4. display results\n");
}

void display:: execute(){
        std::string s;
        int x;
        char * intStr;
    if(!dataCommand.checkUploaded()){
        dio.write("please upload data");
        return;
    }
    if(!dataCommand.checkClassified()){
        dio.write("please classify the data");
        return;
    }
    for(i=0;i<dataCommand.getUnclassified().size();i++){
        x=i+1;
        intStr=itoa(x);
        s=string (intStr);
        s=s.append(" ");
        s=s.append(dataCommand.getUnclassified().at(i).type);
        s=s.append("\n");
        dio->write(s);
    }
    dio->write("Done.\n")
    dio->write("$");
}