//
// Created by weiheling on 2019/6/19.
//

#ifndef ALGORITHMS_SHELLSORT_H
#define ALGORITHMS_SHELLSORT_H

#include <iostream>
using namespace std;
/**
 * 希尔排序  插入排序的优化
 * 使用场合  近乎有序的数列  O(n)
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void shellSort(T arr[], int n) {
    int h = 1;
    while (h < n / 3)
        h = h * 3 + 1;
    // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            T e = arr[i];
            int j;
            for (j = i; j >= h && e < arr[j - h]; j -= h) {
                arr[j] = arr[j - h];
            }
            arr[j] = e;
        }
        h /= 3;
    }
}

#endif //ALGORITHMS_SHELLSORT_H
