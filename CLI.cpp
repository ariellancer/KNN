//
// Created by ariel on 1/17/23.
//

#include "CLI.h"
#include "Command.h"
#include "upload.h"
#include "settings.h"
#include "classify.h"
#include "display.h"
#include "download.h"
#include "finish.h"
#include "vector"
#include <iostream>
#include "Data_Command.h"


using namespace std;
CLI::CLI(DefaultIO* dio) {
    this->dio=dio;
}

void CLI::start() {
    string str;
    Data_Command *data=new Data_Command;
    int choice;
//    int numOfNeighbors=5;
 //   std::string nameOfFunction=("AUC");
//    bool uploaded= false;
  //  bool classified= false;
  //  Command arr[6]={};
    vector<Command*> vec;
    vec.push_back(new upload(data));
    vec.push_back(new settings(data));
    vec.push_back(new classify(data));
    vec.push_back(new display(data));
    vec.push_back(new download(data));
    vec.push_back(new finish());
//    arr[0]=new first_command();
//    arr[1]=new second_command();
//    arr[2]=new third_command();
//    arr[3]=new forth_command();
//    arr[4]=new fifth_command();
//    arr[5]=new finish();
str="Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (int i=0;i<6;i++){
        str=str.append(vec.at(i)->getDescription());
    }
    while(true){
        dio->write(str);
        choice=stoi(dio->read());
        switch (choice) {
            case 1:
                vec.at(0)->setDio(this->dio);
                vec.at(0)->execute();
                break;
            case 2:
                vec.at(1)->setDio(this->dio);
                vec.at(1)->execute();
                break;
            case 3:
                vec.at(2)->setDio(this->dio);
                vec.at(2)->execute();
                break;
            case 4:
                vec.at(3)->setDio(this->dio);
                vec.at(3)->execute();
                break;
            case 5:
                vec.at(4)->setDio(this->dio);
                vec.at(4)->execute();
                break;
            case 8:
                vec.at(5)->setDio(this->dio);
                vec.at(5)->execute();
                return;
            default:
                this->dio->write("invalid input\n");
                break;

        }

    }

}