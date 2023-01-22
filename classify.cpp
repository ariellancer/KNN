//
// Created by ariel on 1/17/23.
//

#include "classify.h"
#include "knn_implement.h"
#include "extractFunc.h"
#include <cstring>


using namespace std;
classify::classify(Data_Command *dc){
    dataCommand=dc;
    setDescription("3. classify data\n");
}

void classify::execute() {
    std::string s;
    char arr[this->dataCommand->getNameOfFunction().length()+1];
    strcpy(arr, this->dataCommand->getNameOfFunction().c_str());
    Distance* distance= getTheMethodOfDistance(arr);
  if(!dataCommand->checkUploaded())  {
      dio->write("please upload data\n");
      return;
  }
    vector<Vector> temp=dataCommand->getUnclassified();

    for(int i=0;i<temp.size();i++){
    s = Knn(dataCommand->getNumOfNeighbors(),dataCommand->getClassified(),
            temp.at(i).vec,distance);
    temp.at(i).type=s;
    }
    dataCommand->setUnclassified(temp);
  dataCommand->updateClassified();
  dio->write("classifying data complete\n");
}