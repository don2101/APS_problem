//
// Created by 염희돈 on 2019-09-29.
//

#include "TreeTest.h"


#include <ctime>
#include <cstdlib>
#include <time.h>

#define LARGE_NUM 10000

const int arraySize = 10000;

int getRandomTreeNumber() {
    int num = rand() % LARGE_NUM + 1;

    return num;
}

void IndexedTreeTest() {
    srand((unsigned int)time(NULL));

    int *tree;

    int array[arraySize];

    for(int i = 0; i < arraySize; ++i) {
        array[i] = getRandomTreeNumber();
    }

    tree = init(array, 10000);

    for(int i = 0; i < 1000; ++i) {
        int command = getRandomTreeNumber() % 2;

        if(command & 1) {
            int position = getRandomTreeNumber() % arraySize;
            int number = getRandomTreeNumber();
            update(tree, position, number);
        } else {
            int left = getRandomTreeNumber() % 5000;
            int right = getRandomTreeNumber() % 5000 + 5000;

            long long sumNumber = sum(tree, left, right);
            cout << "Sum: " << sumNumber << endl;
        }

    }

}
