//
// Created by dfild on 13/12/2022.
//
#include "Vector.h"
#include "Distance.h"

#ifndef ASS_2_KNN_IMPLEMENT_H
#define ASS_2_KNN_IMPLEMENT_H


std::string Knn(int K, std::vector<Vector> vectors, std::vector<double> vec, Distance *distance);
void bubbleSort(Distance *distance, std::vector<Vector> &vectors, std::vector<double> vec);
void swap(Vector &vec1, Vector &vec2);
std::string findMostCommonType(int K, std::vector<Vector> vectors);
bool compare_to(Vector vec1,Vector vec2);
void calculate(Distance *distance, std::vector<Vector> &vectors, std::vector<double> vec);


#endif //ASS_2_KNN_IMPLEMENT_H
