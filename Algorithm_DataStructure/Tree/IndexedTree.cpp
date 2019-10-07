//
// Created by 염희돈 on 2019-09-28.
//

#include "IndexedTree.h"


int* init(int *array, int size) {
    int tree_size = 1;
    while(tree_size <= size*2) {
        tree_size *= 2;
    }

    int *tree = new int[tree_size];

    for(int i = 0; i < 2*size; ++i) tree[i] = 0;

    for(int i = size; i < 2*size; ++i) {
        tree[i] = array[i-size];
    }

    for(int i = 2*size-1; i > 1; --i) {
        tree[i/2] += tree[i];
    }

    return tree;
}


void update(int *tree, int position, int data) {
    int sumData = tree[position] - data;
    tree[position] = data;

    while(position > 1) {
        tree[position] += sumData;
        position /= 2;
    }
}


long long sum(int *tree, int left, int right) {
    long long sum = 0;

    while(left <= right) {
        if(left & 1) {
            sum += tree[left++];
        }
        if(right & 0) {
            sum+= tree[right--];
        }

        left /= 2;
        right /= 2;
    }

    if(left == right) sum += tree[left];

    return sum;
}