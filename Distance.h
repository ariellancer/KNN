//
// Created by ariel on 12/6/22.
//
#include <vector>

#ifndef EX_2MITKADEM_DISTANCE_H
#define EX_2MITKADEM_DISTANCE_H
/**
 * abstract class of distance that declares on a virtual method called calculateDistance.
 */
class Distance {
public:
    virtual double calculateDistance(std::vector<double> firstVec, std::vector<double> secVec)=0;
};


#endif //EX_2MITKADEM_DISTANCE_H
