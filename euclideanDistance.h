//
// Created by ariel on 12/8/22.
//
#include "Distance.h"

#ifndef EX_2MITKADEM_EUCLIDEANDISTANCE_H
#define EX_2MITKADEM_EUCLIDEANDISTANCE_H

/**
 * class of euclideanDistance method.
 */
class euclideanDistance: public Distance {
public:
    double calculateDistance(std::vector<double> firstVec, std::vector<double> secVec) override;

};


#endif //EX_2MITKADEM_EUCLIDEANDISTANCE_H
