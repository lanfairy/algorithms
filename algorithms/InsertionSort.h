//
// Created by weiheling on 2019/6/19.
//

#ifndef ALGORITHMS_INSERTIONSORT_H
#define ALGORITHMS_INSERTIONSORT_H

#include <iostream>
using namespace std;
/**
 * 插入排序
 * 使用场合  近乎有序的数列  O(n)
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void insertionSort(T arr[], int n){
    for (int i = 1; i < n; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1]>e; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}
// 对arr[l...r]范围的数组进行插入排序
template<typename T>
void insertionSort(T arr[], int l, int r){

    for( int i = l+1 ; i <= r ; i ++ ) {

        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}

/**

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        // 寻找元素arr[i]合适的插入位置
        // 写法1
//        for( int j = i ; j > 0 ; j-- )
//            if( arr[j] < arr[j-1] )
//                swap( arr[j] , arr[j-1] );
//            else
//                break;

//写法2
//        for (int j = i; j > 0 && arr[j]<arr[j-1]; j--) {
//            swap(arr[j-1], arr[j]);
//        }

//写法3
        int j;// j保存元素e应该插入的位置
        T e = arr[i];
        for (j = i; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
} */

#endif //ALGORITHMS_INSERTIONSORT_H
