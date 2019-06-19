//
// Created by weiheling on 2019/6/19.
//

#ifndef ALGORITHMS_COCKTAILSORT_H
#define ALGORITHMS_COCKTAILSORT_H

#include <iostream>

using namespace std;

/**
 * 鸡尾酒排序是基于冒泡排序做的一点点优化
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void cockTailSort(T arr[], int n) {

    //记录左侧最后一次交换的位置
    int lastLeftExchangeIndex = 0;
    //记录右侧最后一次交换的位置
    int lastRightExchangeIndex = 0;
    //无序数列的左边界，每次比较只需要比到这里为止
    int leftSortBorder = 0;
    //无序数列的右边界，每次比较只需要比到这里为止
    int rightSortBorder = n - 1;
    for (int i = 0; i < n / 2; ++i) {
        //有序标记，每一轮的初始是true
        bool isSorted = true;
        //奇数轮，从左向右比较和交换
        for (int j = leftSortBorder; j < rightSortBorder; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                //有元素交换，所以不是有序，标记变为false
                isSorted = false;
                lastRightExchangeIndex = j;
            }
        }
        rightSortBorder = lastRightExchangeIndex;
        if (isSorted)break;

        //偶数轮 从右向左比较和交换
        //偶数轮之前，重新标记为true
        isSorted = true;
        for (int j = rightSortBorder; j > leftSortBorder ; j--) {
            if (arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
                isSorted = false;
                lastLeftExchangeIndex = j;
            }
        }
        leftSortBorder = lastLeftExchangeIndex;
        if (isSorted)break;
    }

}

#endif //ALGORITHMS_COCKTAILSORT_H
