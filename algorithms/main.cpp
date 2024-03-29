#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"
#include "CockTailSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"



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

int main1() {

    int n = 1000000;
    int *arr = SortTestHepler::generateRandomArray(n, 0, n);
//    int *arr = SortTestHepler::generateNearlyOrderedArray(n, 200);
//    int *arr2 = SortTestHepler::copyIntArray(arr, n);
    int *arrShell = SortTestHepler::copyIntArray(arr, n);
//    int *arr4 = SortTestHepler::copyIntArray(arr, n);
//    int *arrBubble = SortTestHepler::copyIntArray(arr, n);
    int *arrMerge = SortTestHepler::copyIntArray(arr, n);
//    selectionSort(arr, n);
//    SortTestHepler::testSort("selectionSort", selectionSort, arr, n);
//    SortTestHepler::testSort("insertionSort", insertionSort, arr2, n);
//    SortTestHepler::testSort("cockTailSort", cockTailSort, arr4, n);
//    SortTestHepler::testSort("bubbleSort", bubbleSort2, arrBubble, n);
    SortTestHepler::testSort("shellSort", shellSort, arrShell, n);
    SortTestHepler::testSort("mergeSort", mergeSort, arrMerge, n);
    delete[] arr;
//    delete (arr2);
    delete[] arrShell;
//    delete (arr4);
//    delete (arrBubble);
    delete[] arrMerge;


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
int main(){

// 比较Merge Sort和双路快速排序和三路快排三种排序算法的性能效率
// 对于包含有大量重复数据的数组, 三路快排有巨大的优势
// 对于一般性的随机数组和近乎有序的数组, 三路快排的效率虽然不是最优的, 但是是在非常可以接受的范围里
// 因此, 在一些语言中, 三路快排是默认的语言库函数中使用的排序算法。比如Java:)
    int n = 10000000;
    // 测试1 一般性测试
    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHepler::generateRandomArray(n,0,n);
    int* arr2 = SortTestHepler::copyIntArray(arr1,n);
    int* arr3 = SortTestHepler::copyIntArray(arr1,n);

    SortTestHepler::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHepler::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHepler::testSort("Quick Sort 3 Way", quickSort3Way, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout<<endl;


    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHepler::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHepler::copyIntArray(arr1, n);
    arr3 = SortTestHepler::copyIntArray(arr1, n);

    SortTestHepler::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHepler::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHepler::testSort("Quick Sort 3 Way", quickSort3Way, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout<<endl;


    // 测试3 测试存在包含大量相同元素的数组
    cout<<"Test for Random Array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHepler::generateRandomArray(n,0,10);
    arr2 = SortTestHepler::copyIntArray(arr1, n);
    arr3 = SortTestHepler::copyIntArray(arr1, n);

    SortTestHepler::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHepler::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHepler::testSort("Quick Sort 3 Way", quickSort3Way, arr3, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}