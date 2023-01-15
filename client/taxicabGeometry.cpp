//
// Created by ariel on 12/8/22.
//

#include "taxicabGeometry.h"
#include <cmath>
using namespace std;

/**
 * Function in charge of calculating the distance of tow vectors according to taxicabGeometry method.
 * @param firstVec
 * @param secVec
 * @return the distance.
 */
double taxicabGeometry::calculateDistance(std::vector<double> firstVec, std::vector<double> secVec) {
    double sum;
    for(int i=0;i<firstVec.size();i++){
        sum=sum+ abs(firstVec.at(i)-secVec.at(i));
    }

    return sum;
}