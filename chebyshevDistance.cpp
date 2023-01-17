//
// Created by ariel on 12/8/22.
//

#include "chebyshevDistance.h"
#include <math.h>

using namespace std;
/**
 * Function in charge of calculating the distance of tow vectors according to chebyshevDistance method.
 * @param firstVec
 * @param secVec
 * @return distance.
 */
double chebyshevDistance::calculateDistance(std::vector<double> firstVec, std::vector<double> secVec) {
    int i=0;
    double sum= abs(firstVec.at(i)-secVec.at(i));
    for(i=1;i<firstVec.size();i++){
        if(abs(firstVec.at(i)-secVec.at(i))>sum){
            sum=abs(firstVec.at(i)-secVec.at(i));
        }
    }
    return sum;
};