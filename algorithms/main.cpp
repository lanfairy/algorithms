#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"
#include "CockTailSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"




/**
 * 选择排序  O(n2)
 * @param arr
 * @param n
 */
template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[minIndex], arr[i]);
    }
}

int main() {

    int n = 100000;
    int *arr = SortTestHepler::generateRandomArray(n, 0, n);
//    int *arr = SortTestHepler::generateNearlyOrderedArray(n, 200);
//    int *arr2 = SortTestHepler::copyIntArray(arr, n);
    int *arr3 = SortTestHepler::copyIntArray(arr, n);
//    int *arr4 = SortTestHepler::copyIntArray(arr, n);
//    int *arrBubble = SortTestHepler::copyIntArray(arr, n);
    int *arrMerge = SortTestHepler::copyIntArray(arr, n);
//    selectionSort(arr, n);
//    SortTestHepler::testSort("selectionSort", selectionSort, arr, n);
//    SortTestHepler::testSort("insertionSort", insertionSort, arr2, n);
//    SortTestHepler::testSort("cockTailSort", cockTailSort, arr4, n);
//    SortTestHepler::testSort("bubbleSort", bubbleSort2, arrBubble, n);
    SortTestHepler::testSort("shellSort", shellSort, arr3, n);
    SortTestHepler::testSort("mergeSort", mergeSort, arrMerge, n);
    delete (arr);
//    delete (arr2);
    delete (arr3);
//    delete (arr4);
//    delete (arrBubble);
    delete (arrMerge);


    /*
    std::string c[4] = {"d", "c", "b", "a"};
    selectionSort(c,4);
    SortTestHepler::printArray(c,4);
     */
/*
    // 测试模板函数，传入自定义结构体Student数组
    Student d[4] = { {"D",90} , {"C",100} , {"B",95} , {"A",95} };
    selectionSort(d,4);
    SortTestHepler::printArray(d,4);
    */

    return 0;
}