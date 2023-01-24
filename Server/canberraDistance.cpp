//
// Created by ariel on 12/8/22.
//

#include "canberraDistance.h"
#include <math.h>

using namespace std;
/**
 * Function in charge of calculating the distance of tow vectors according to canberraDistance method.
 * @param firstVec
 * @param secVec
 * @return the distance.
 */
double canberraDistance::calculateDistance(vector<double> firstVec, vector<double> secVec){
    double distance = 0;
    double temp1 = 0;
    double temp2 = 0;
    for (int i = 0; i < firstVec.size(); i++) {
        //Makes an absolute value to the number in the denominator.
        temp1 = abs(firstVec.at(i) - secVec.at(i));
        //connects the absolute value of the numbers in the denominator.
        temp2 = abs(firstVec.at(i)) + abs(secVec.at(i));
        //add the sum to the distance.
        distance = distance + temp1 / temp2;
    }
    return distance;
}