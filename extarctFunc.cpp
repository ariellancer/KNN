//
// Created by ariel on 12/5/22.
//
#include <iostream>
#include <stdexcept>
#include <fstream>
#include "server/Vector.h"
#include <string.h>
#include <sstream>
#include "server/euclideanDistance.h"
#include "server/canberraDistance.h"
#include "server/chebyshevDistance.h"
#include "minkowskiDistance.h"
#include "taxicabGeometry.h"

using namespace std;


/**
 * The function is in charge to check if the str (the string) is legal according
 * to what we expect to get from the user.
 * @param str
 * @return true if the str is valid, otherwise false.
 */
bool check(char *str) {
    size_t ind;
    double num;
    try {
        num=stod(str,&ind);
        if(ind< strlen(str)){
            return false;
        }
    }catch (exception e){
        return false;
    }

    return true;
}

/**
 * Function in charge of extracting and initializing a Vector that is represented in an array.
 * @param str
 * @param size
 * @return the initialized Vector.
 */
Vector initializationOfVector(char *str, int size) {
    Vector vector;
    int counter=0;
    char *temp;
    char *ptr;
    double num;
    bool flag;
    temp = strtok(str, ",");
    while (temp) {
        flag = check(temp);
        if (!flag) {
            if(counter==size){
                vector.type=temp;
                return vector;
            } else{
                throw invalid_argument("invalid vector");
            }
        }
        num = strtod(temp, &ptr);
        vector.vec.push_back(num);
        counter++;
        temp = strtok(NULL, ",");
    }
    throw invalid_argument("invalid vector");
}


/**
 * The function is in charge os getting the number of neighbors the user wants to run the KNN on.
 * @param str
 * @return number of neighbors.
 */
int getNumberOfNeighbors(char* str){

    int num=atoi(str);
    if(num==0){
        if(strcmp(str,"0")==0){
            return num;
        }else{
            throw invalid_argument("invalid number of neighbors");
        }
    }
    return num;
}
/**
 * The function is in charge of checking the number of values there are in the vector that is represented
 * with an array of chars.
 * @param arr
 * @return the number of values.
 */
int getSize(char* arr){
    char * temp;
    int counter=0;
    temp= strtok(arr,",");
    while (temp){
        counter++;
        temp= strtok(NULL,",");
    }
    return counter-1;
}
/**
 * The function is in charge of initializing the the file we got from the user so we could run on the vectors
 * in the file the KNN.
 * @param path
 * @return
 */
vector<Vector> initializingTheVectors(char * path){
    int lengthOfVector;
    bool check=false;
    string data;
    Vector vec;
    vector<Vector> arrayOfVectors;

    ifstream infile;
    infile.open((path));
    if (infile.is_open()) {
        while (infile) {
            getline(infile,data);
            char arr[data.length()+1];
            strcpy(arr,data.c_str());
            if(!check){
                char copy[data.length()+1];
                strcpy(copy,data.c_str());
                lengthOfVector= getSize(copy);
                check= true;
            }

            vec= initializationOfVector(arr,lengthOfVector);

            if(vec.vec.size()!=lengthOfVector){
                throw invalid_argument ("the length of a vector is not valid");
            }
            arrayOfVectors.push_back(vec);
        }
    }
    return arrayOfVectors;
}

/**
 * This function is in charge to check what distance method the user wants to run the KNN with' and return
 * an object of the wanted method.
 * @param nameOfFunction
 * @return a pointer to the distance object wanted.
 */
Distance* getTheMethodOfDistance(char * nameOfFunction){
    if(strcmp(nameOfFunction,"AUC")==0){
        return new euclideanDistance();
    }
    if(strcmp(nameOfFunction,"MAN")==0){
        return new taxicabGeometry();
    }
    if(strcmp(nameOfFunction,"CHB")==0){
        return new chebyshevDistance();
    }
    if(strcmp(nameOfFunction,"CAN")==0){
        return new canberraDistance();
    }
    if(strcmp(nameOfFunction,"MIN")==0){
        return new minkowskiDistance();
    }
    throw invalid_argument("the name of distance function is not valid");
}

/**
 * Function is in charge of getting vector frm user.
 * @return
 */
vector<char*> getVectorFromUser(char* buffer){
    char* temp;
    char* ptr;
    bool flag,flag3,flag2 = false;
    vector<char*>vec;
    temp= strtok(buffer," ");
    while (temp!=NULL){
        flag= check(temp);
        if(!flag){
            Distance* distance = getTheMethodOfDistance(temp);
            flag2 = true;
        }
        vec.push_back(temp);
        if(flag2) {
            temp=strtok(NULL," ");
            int num = getNumberOfNeighbors(temp);;
            vec.push_back(temp);
            temp=strtok(NULL," ");
            if(temp!= NULL){
                throw invalid_argument("there is more args than it shold be");
            }
        }
        temp=strtok(NULL," ");
    }
    return vec;
}


bool stop(string str){
    if(str=="-1"){
        return true;
    } else{
        return false;
    }
}


int extractPort(char* port){
    int num=atoi(port);
    if (num==0){
        if(strcmp(port,"0")==0){
            return num;
        }else{
            throw invalid_argument("invalid number of port");
        }
    }
    if(num>0 && num<=65535){
        return num;
    }else{
        throw invalid_argument("invalid number of port");
    }
}