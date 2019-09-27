//
// Created by 염희돈 on 2019-09-27.
//

#include "InsertionSort.h"

void swap(int *array, int i, int j) {
    int temp = array[j];
    array[j] = array[i];
    array[i] = temp;
}

void insertionSort(int *array, int length) {
    for(int i = 1; i < length; ++i) {
        int j = i-1;
        int number = array[i];

        while(j >= 0 && array[j] > number) {
            swap(array, j, j+1);
            j--;
        }

        array[j+1] = number;
    }
}
