//
// Created by weiheling on 2019/6/19.
//

#ifndef ALGORITHMS_BUBBLESORT_H
#define ALGORITHMS_BUBBLESORT_H

#include <iostream>
using namespace std;
template<typename T>
void bubbleSort1(T arr[], int n){
bool swapped = false;
    do{
        swapped = false;
        for (int i = 0; i < n; ++i) {
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        n--;
    }while (swapped);
}
template<typename T>
void bubbleSort2(T arr[], int n){
    int newn = 0;
    do{
        newn = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                // 记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
                newn = i;
            }
        }
        n = newn;
    }while (newn>0);
}

/**
 * 冒泡排序
 */
template<typename T>
void bubbleSort(T arr[], int n) {

    bool swapped;
    //int newn; // 理论上,可以使用newn进行优化,但实际优化效果较差

    do {
        swapped = false;
        //newn = 0;
        for (int i = 1; i < n; i++)
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swapped = true;

                // 可以记录最后一次的交换位置,在此之后的元素在下一轮扫描中均不考虑
                // 实际优化效果较差,因为引入了newn这个新的变量
                //newn = n;
            }

        //n = newn;

        // 优化,每一趟Bubble Sort都将最大的元素放在了最后的位置
        // 所以下一次排序,最后的元素可以不再考虑
        // 理论上,newn的优化是这个优化的复杂版本,应该更有效
        // 实测,使用这种简单优化,时间性能更好
        n--;

    } while (swapped);
}
#endif //ALGORITHMS_BUBBLESORT_H
