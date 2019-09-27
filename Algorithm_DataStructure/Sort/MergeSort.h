//
// Created by 염희돈 on 2019-09-27.
//

#ifndef ALGORITHM_DATASTRUCTURE_MERGESORT_H
#define ALGORITHM_DATASTRUCTURE_MERGESORT_H
#include <iostream>

using namespace std;

void mergeSort(int *array , int length);
void divide(int *array, int start, int end);
void merge(int *array, int start, int mid, int end);


#endif //ALGORITHM_DATASTRUCTURE_MERGESORT_H
