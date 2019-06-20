//
// Created by weiheling on 2019/6/18.
//

#ifndef ALGORITHMS_SORTTESTHELPER_H
#define ALGORITHMS_SORTTESTHELPER_H
#include <iostream>
#include <cassert>
#include <ctime>
namespace SortTestHepler {
    // 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
    //调用完后 需要手动释放 数组开辟的内存 delete(arr);
    int* generateRandomArray(int n, int rangeL, int rangeR){
        assert(rangeL<=rangeR);
        int *arr  = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    int *generateNearlyOrderedArray(int n, int swapTimes){
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }

        srand(time(NULL));
        for (int i = 0; i < swapTimes; ++i) {
            int posx = rand()%n;
            int posy = rand()%n;
            std::swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    template< typename T>
    void printArray(T arr[], int n){
        for (int i = 0; i < n; ++i) {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }
    template<typename T>
    bool isSorted(T arr[], int n){
        for (int i = 0; i < n-1; ++i) {
            if (arr[i] > arr[i+1])
                return false;
        }
        return true;
    }
template<typename T>
void testSort(const std::string &sortName, void(*sort)(T[], int), T arr[], int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));
        std::cout << sortName << " : "<<double(endTime-startTime) / CLOCKS_PER_SEC << " s" << std::endl;
    }

    int* copyIntArray(int a[], int n){
        int *arr = new int[n];
        std::copy(a, a+n, arr);
        return arr;
    }
};
#endif //ALGORITHMS_SORTTESTHELPER_H
