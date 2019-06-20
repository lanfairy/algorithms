//
// Created by weiheling on 2019/6/20.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

#include <iostream>
#include <ctime>
#include "InsertionSort.h"

using namespace std;


template<typename T>
int __partition(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];
    int i = l+1, j = r;
    while (true){
        while (i<=r && arr[i]<v) i++;
        while (j>=l+1 && arr[j]>v) j--;
        if (i>j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[l],arr[j]);
    return j;
    swap(arr[l],arr[i]);
    return i;
}

template<typename T>
void __quickSort(T arr[], int l, int r) {
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }
    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}

#endif //ALGORITHMS_QUICKSORT_H
