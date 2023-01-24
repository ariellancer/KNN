//
// Created by ariel on 12/8/22.
//
#include "Distance.h"
#ifndef EX_2MITKADEM_CHEBYSHEVDISTANCE_H
#define EX_2MITKADEM_CHEBYSHEVDISTANCE_H

/**
 * class of chebyshevDistance method.
 */
class chebyshevDistance: public Distance{
public:
    double calculateDistance(std::vector<double> firstVec, std::vector<double> secVec) override;
};


#endif //EX_2MITKADEM_CHEBYSHEVDISTANCE_H
