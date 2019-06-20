//
// Created by weiheling on 2019/6/20.
//

#ifndef ALGORITHMS_QUICKSORT_H
#define ALGORITHMS_QUICKSORT_H

#include <iostream>
#include <ctime>
#include "InsertionSort.h"

using namespace std;


// 递归的三路快速排序算法
template<typename T>
void __quickSort3Way(T arr[], int l, int r) {
    // 对于小规模数组, 使用插入排序进行优化
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    // 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];
    //arr[l+1 ...  lt] < v      arr[lt+1 ... i) = v      arr[gt ... r]  > v
    int lt = l;
    int i = l + 1;
    int gt = r + 1;
    while (i<gt){
        if (arr[i]<v){
            swap(arr[i], arr[lt+1]);
            i++;
            lt++;
        } else if (arr[i]>v){
            swap(arr[i],arr[gt-1]);
            gt--;
        } else{// arr[i] == v
            i++;
        }
    }
    swap(arr[l], arr[lt]);

    __quickSort3Way(arr,l,lt-1);
    __quickSort3Way(arr,gt,r);
}

template<typename T>
void quickSort3Way(T arr[], int n) {
    srand(time(NULL));
    __quickSort3Way(arr, 0, n - 1);
}

//双路快速排序
template<typename T>
int __partition(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];
    int i = l + 1, j = r;
    while (true) {
        while (i <= r && arr[i] < v) i++;
        while (j >= l + 1 && arr[j] > v) j--;
        if (i > j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[l], arr[j]);
    return j;
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
