//
// Created by dfild on 13/12/2022.
//

#include "knn_implement.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <map>
#include "Vector.h"
#include "algorithm"
using namespace std;

bool compare_to(Vector vec1,Vector vec2){
    return vec1.distance<vec2.distance;
}

/**
 * the function is in charge of running the KNN algorithm and printing according to the KNN
 * the type of the given vector.
 * @param K
 * @param vectors
 * @param vec
 * @param distance
 */
string Knn(int K, vector<Vector> vectors, vector<double> vec, Distance *distance){
    if (K > vectors.size()){
        K = vectors.size();
    }
    if(vec.size()!=vectors.at(0).vec.size()){
        string mostCommonType = "invalid input";
        return mostCommonType;
    }
    calculate(distance,vectors,vec);
    sort(vectors.begin(),vectors.end(), compare_to);
    //bubbleSort(distance, vectors, vec);
    string mostCommonType = findMostCommonType(K, vectors);
    return mostCommonType;
}

void calculate(Distance *distance, std::vector<Vector> &vectors, std::vector<double> vec){
    int i;
    for (i=0;i<vectors.size()-1;i++){
        vectors.at(i).distance=distance->calculateDistance(vectors.at(i).vec,vec);
    }

}

// A function to implement bubble sort
void bubbleSort(Distance *distance, vector<Vector>& vectors, vector<double> vec) {
    int i, j,x;
    x=vectors.size()-1;
    for (i = 0; i < x ; i++)
        // Last i elements are already
        // in place
        for (j = 0; j < x - i ; j++){
            double firstDis=distance->calculateDistance(vectors.at(j).vec,vec);
            double secDis=distance->calculateDistance(vectors.at(j+1).vec,vec);
            if(firstDis>secDis){
                swap(vectors.at(j), vectors.at(j+1));
            }
        }
}
/**
 * A function to implement swap.
 * @param vec1
 * @param vec2
 */
void swap(Vector &vec1, Vector &vec2){
    Vector v = vec1;
    vec1 = vec2;
    vec2 = v;
}
/**
 * A function that checks the most common type of the k neighbors.
 * @param K
 * @param vectors
 * @return
 */
string findMostCommonType(int K, vector<Vector> vectors){
    map<string,int> map;
    for(int i=0; i<K; i++){
        if(map.count(vectors.at(i).type)){
            map.at(vectors.at(i).type)++;
        }else{
            map.insert({vectors.at(i).type, 1});
        }
    }
    string curr;
    int max = 0;
    for(auto & it : map){
        if(max<it.second){
            curr = it.first;
            max = it.second;
        }
    }
    return curr;
}
