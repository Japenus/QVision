#include "Sort.h"
Sort::Sort()
{

}

Sort::~Sort()
{

}

void Sort::swapData(int &num1,int &num2)
{
    int temp=num1;
    num1=num2;
    num2=temp;
}

void Sort::bubblesort(QVector<int> &array)
{
    for(int i=0;i<array.size()-1;i++){
        for(int j=0;j<array.size()-i-1;j++){
            if(array[j]>array[j+1]){
                swapData(array[j],array[j+1]);
            }
        }
    }
}


void Sort::heapify(QVector<int> &array, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && array[left] > array[largest]) {
        largest = left;
    }
    if (right < n && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, n, largest);
    }
}

void Sort::heapSort(QVector<int> &array)
{
    int n = array.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}


void Sort::insertSort(QVector<int> &array)
{
    int index;
    int current;
    for(int i=1;i<array.size();i++)
    {
        index=i-1;
        current=array[i];
        while(index>=0 && array[index]>current)
        {
            array[index+1]=array[index];
            index--;
        }
        array[index+1]=current;
    }
}

void Sort::mergeSort(QVector<int> &array, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void Sort::merge(QVector<int> &array, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    QVector<int> leftArray(n1);
    QVector<int> rightArray(n2);
    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = array[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void Sort::quickSort(QVector<int> &array, int left, int right)
{
    if (left >= right) return;
    int pivot = array[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    quickSort(array, left, j);
    quickSort(array, i, right);
}


void Sort::selectSort(QVector<int> &array)
{
    int index;
    for(int i=0;i<array.size();i++){
        index=i;
        for(int j=i+1;j<array.size();j++)
        {
            if(array[j]<array[index])
            {
                index=j;
            }
        }
        swapData(array[i],array[index]);
    }
}

void Sort::shellSort(QVector<int> &array)
{
    for(int gap=array.size()/2;gap>0;gap/=2){
        for(int i=gap;i<array.size();i++){
            int j=i;
            int temp=array[j];
            while(j-gap>=0 && temp<array[j-gap]){
                array[j]=array[j-gap];
                j-=gap;
            }
            array[j]=temp;
        }
    }
}
