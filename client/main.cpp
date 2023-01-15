//#include <iostream>
//#include "extractFunc.h"
//#include "Distance.h"
//#include "knn_implement.h"
//
//
//using namespace std;
///**
// * The main function that is in charge of calling the functions to initialize and run the
// * KNN algorithm.
// * @param argc
// * @param argv
// * @return
// */
//int main(int argc,char **argv) {
//    try {
//        int numOfNeighbors=getNumberOfNeighbors(argv[1]);
//        vector<Vector> arrayOfVectors= initializingTheVectors(argv[2]);
//        Distance* func=getTheMethodOfDistance(argv[3]);
//        while(true){
//            vector<double>vector=getVectorFromUser();
//            if(vector.size()!=arrayOfVectors.at(1).vec.size()){
//                throw invalid_argument("invalid input");
//            }
//            Knn(numOfNeighbors,arrayOfVectors,vector,func);
//        }
//    }catch(exception e){
//        cout<<e.what()<<endl;
//    }
//
//
//
//    return 0;
//}
