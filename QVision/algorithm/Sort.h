#ifndef Sort_H
#define Sort_H
#include"Global.h"
class Sort
{
public:
    Sort();
    ~Sort();
    static Sort& ins(){static Sort s;return s;}
public:
    void swapData(int &num1,int &num2);
    void heapSort(QVector<int> &array);
    void shellSort(QVector<int> &array);
    void bubblesort(QVector<int> &array);
    void selectSort(QVector<int> &array);
    void insertSort(QVector<int> &array);
    void adjustHeap(QVector<int> &array,int i);
    void heapify(QVector<int> &array, int n, int i);
    void quickSort(QVector<int> &array, int left, int right);
    void mergeSort(QVector<int> &array, int left, int right);
    void merge(QVector<int> &array, int left, int mid, int right);
};

#endif // Sort_H
