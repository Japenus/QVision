#pragma once
#define DATAEXCHANGEDLL_API __declspec(dllexport)
extern "C"	DATAEXCHANGEDLL_API void shellSort(int* arr);
extern "C"	DATAEXCHANGEDLL_API void selectSort(int* arr);
extern "C"	DATAEXCHANGEDLL_API void insertSort(int* arr);
extern "C"	DATAEXCHANGEDLL_API void bubbleSort(int *arr);