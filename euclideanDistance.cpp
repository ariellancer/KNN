//
// Created by ariel on 12/8/22.
//

#include "euclideanDistance.h"
#include <math.h>

using namespace std;

/**
 * Function in charge of calculating the distance of tow vectors according to euclideanDistance method.
 * @param firstVec
 * @param secVec
 * @return the distance.
 */
double euclideanDistance::calculateDistance(std::vector<double> firstVec, std::vector<double> secVec) {
    double sum;
    for(int i=0;i<firstVec.size();i++){
        sum=sum+ pow((firstVec.at(i)-secVec.at(i)),2);
    }
    sum= sqrt(sum);
    return sum;
}