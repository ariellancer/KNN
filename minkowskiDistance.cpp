//
// Created by ariel on 12/8/22.
//

#include "minkowskiDistance.h"
#include <math.h>
using namespace std;

/**
 * Function in charge of calculating the distance of tow vectors according to minkowskiDistance method.
 * @param firstVec
 * @param secVec
 * @return the distance.
 */
double minkowskiDistance::calculateDistance(std::vector<double> firstVec, std::vector<double> secVec) {
    double distance = 0;
    double temp = 0;
    double p = 2;
    double temp5 = 1 / p;
    for (int i = 0; i < firstVec.size(); i++) {
        temp = abs(firstVec.at(i) - secVec.at(i));
        temp = pow(temp, p);
        distance = distance + temp;
    }
    distance = pow(distance, temp5);
    return distance;
}