//
// Created by 염희돈 on 2019-09-27.
//

#include "SortTest.h"

#include <ctime>
#include <cstdlib>
#include <time.h>

#define LARGE_NUM 1000000


const int arraySize = 10000;


void printArray(int *array, int length) {
    for(int i = 0; i < length; ++i) cout << array[i] << " ";
    cout << endl;
}

int getRandomSortNumber() {
    int num = rand() % LARGE_NUM + 1;

    return num;
}

void mergeSortTest() {
    srand((unsigned int)time(NULL));

    int array[arraySize];
    int start, end;

    for(int i = 0; i < arraySize; ++i) {
        array[i] = getRandomSortNumber();
    }

    start = clock();
    mergeSort(array, arraySize);
    end = clock();

    cout << "Merge Sort: " << (double)(end - start) << "ms" << endl;

    for(int i = 0; i < arraySize; ++i) {
        array[i] = getRandomSortNumber();
    }

    start = clock();
    insertionSort(array, arraySize);
    end = clock();

    cout << "Insertion Sort: " << (double)(end - start) << "ms" << endl;
}



