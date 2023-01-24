//
// Created by ariel on 1/17/23.
//

#include "download.h"


//
// Created by ariel on 1/17/23.
//

#include "display.h"
#include "string.h"
#include "iostream"
#include <stdio.h>
#include <stdlib.h>

using namespace std;
download::download(Data_Command * dc){
    this->dataCommand=dc;
    setDescription("5. download results\n");
}

void download:: execute(){
    std::string s;
    int x;
    string intStr;
    if(!dataCommand->checkUploaded()){
        dio->write("please upload data$");
        return;
    }
    if(!dataCommand->checkClassified()){
        dio->write("please classify the data$");
        return;
    }
    dio->write("$");
    s=dio->read();
    if(s.compare("close")==0){
        return;
    }
    for(int i=0;i<dataCommand->getUnclassified().size();i++){
        x=i+1;
        intStr= to_string(x);
        s=s.append(intStr);
        s=s.append(" ");
        s=s.append(dataCommand->getUnclassified().at(i).type);
        s=s.append("\n");
    }
    dio->write(s);
    dio->write("$");
}