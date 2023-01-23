//
// Created by ariel on 12/8/22.
//
#include "Distance.h"
#ifndef EX_2MITKADEM_TAXICABGEOMETRY_H
#define EX_2MITKADEM_TAXICABGEOMETRY_H

/**
 * class of taxicabGeometry method.
 */
class taxicabGeometry: public Distance{
public:
    double calculateDistance(std::vector<double> firstVec, std::vector<double> secVec) override;

};


#endif //EX_2MITKADEM_TAXICABGEOMETRY_H
