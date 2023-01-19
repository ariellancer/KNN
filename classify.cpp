//
// Created by ariel on 1/17/23.
//

#include "classify.h"
#include "knn_implement.h"
#include "extractFunc.h"


using namespace std;
classify::classify(Data_Command &dc){
    dataCommand=dc;
    setDescription("3. classify data\n");
}

void classify::execute() {
    std::string s;
    Distance* distance= getTheMethodOfDistance(dataCommand.getNameOfFunction());
  if(!dataCommand.checkUploaded())  {
      dio->write("please upload data\n");
      return;
  }
  for(int i=0;i<dataCommand.getUnclassified().size();i++){
    s = Knn(dataCommand.getNumOfNeighbors(),dataCommand.getClassified(),
            dataCommand.getUnclassified().at(i).vec,distance);
    dataCommand.getUnclassified().at(i).type=s;
    }
  dataCommand.updateClassified();
  dio->write("classifying data complete\n");
}