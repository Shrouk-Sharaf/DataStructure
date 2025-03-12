#ifndef DATASTRUCTURE_SORTINGSYSTEM_H
#define DATASTRUCTURE_SORTINGSYSTEM_H

#include <iostream>
using namespace std;

template <typename T>
class SortingSystem {
private:
    T* data;
    int size;

public:
    SortingSystem(int n);
    ~SortingSystem();

    void setData();

    void selectionSort();
    void bubbleSort();
    void radixSort();
    void shellSort();
    void mergeSort(int left, int right);
    void quickSort(int left, int right);
    void countSort();
    void bucketSort();
    void insertionSort();


    void merge(int left, int mid, int right);
    int partition(int low, int high);

    void measureSortTime(void (SortingSystem::*sort)());

    void displayData();
    void showMenu();
};

#endif