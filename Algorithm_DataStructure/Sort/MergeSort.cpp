//
// Created by 염희돈 on 2019-09-27.
//

#include "MergeSort.h"

/*
 * 실수 했던 부분
 * 1. 배열 포인트 제어
 * - 배열 부분에서 1차이 오류로 배열을 제대로 제어하지 못함
 * - 해결방법: 배열의 상황을 생각할 때 결국 서로 침범하지 않는 범위로 나누는 것을 생각
 *
 * 2. 정렬 제어
 * - merge 할 때 경우를 제대로 생각하지 않고 생각
 * 해결법: 우선되어야 하는 경우를 먼저 적용
 */

void mergeSort(int *array, int length) {
    divide(array, 0, length-1);
}


void divide(int *array, int start, int end) {
    // case. start보다 end가 같거나 작으면 나눌 필요가 없다
    if(end <= start) return;

    // 1. 일단 두 부분으로 계속 나눈다.
    int mid = (start + end) / 2;

    divide(array, start, mid);
    divide(array, mid+1, end);
    merge(array, start, mid, end);
}


void merge(int *array, int start, int mid, int end) {
    // 1. i = 왼쪽 부분 시작, j = 오른쪽 부분 시작
    int i = start;
    int j = mid+1;
    int length = end-start+1;
    int *tempArray = new int[length];

    // 2. 정렬 부분, i에 있는 수와 j에 있는 수를 비교하며 tempArray에 저장
    for(int k = 0; k < length; ++k) {
        if (i > mid) tempArray[k] = array[j++];
        else if (j > end) tempArray[k] = array[i++];
        else if (array[i] <= array[j]) tempArray[k] = array[i++];
        else tempArray[k] = array[j++];
    }

    // 3. tempArray에 저장된 값을 다시 array로 옮김
    for(int p = start; p <= end; ++p) {
        array[p] = tempArray[p-start];
    }

}