#include "SortingAlgorithms.h"

void BubbleSort(int array[], const int size) {
	for (int i = size - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void SelectionSort(int array[], const int size) {
	for (int i = 0; i < size; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < size; ++j) {
			if (array[j] < array[minIndex]) {
				minIndex = j;
			}
		}
		if (i != minIndex) {
			int temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}

void InsertionSort(int array[], const int size) {

	for (int i = 1; i < size; ++i) {
		for (int j = i; j > 0; --j) {
			if (array[j] >= array[j - 1]) break;
			int temp = array[j];
			array[j] = array[j-1];
			array[j-1] = temp;
		}
	}
}

void MergeSort(int array[], const int leftIndex, const int rightIndex)
{
	if (leftIndex >= rightIndex) return;

	const int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
	MergeSort(array, leftIndex, midIndex);
	MergeSort(array, midIndex + 1, rightIndex);

	Merge(array, leftIndex, midIndex, rightIndex);

}

void Merge(int array[], const int leftIndex, const int midIndex, const int rightIndex)
{
	// Creates two subarrays based on left, mid and right indices.
	const int leftArraySize = midIndex - leftIndex + 1;
	const int rightArraySize = rightIndex - midIndex;

	int* leftArray = new int[leftArraySize];
	int* rightArray = new int[rightArraySize];

	for (int i = 0; i < leftArraySize; ++i)
		leftArray[i] = array[leftIndex + i];
	for (int i = 0; i < rightArraySize; ++i)
		rightArray[i] = array[midIndex + 1 + i];


	// Compares two subarrays and fills original array with ordered data
	int index = leftIndex;
	int i = 0;
	int j = 0;

	while (i < leftArraySize && j < rightArraySize) {
		if (leftArray[i] <= rightArray[j]) {
			array[index] = leftArray[i];
			++index;
			++i;
		}
		else {
			array[index] = rightArray[j];
			++index;
			++j;
		}
	}

	// Copies over the remaining items from the subarray with leftover items.
	while (i < leftArraySize) {
		array[index] = leftArray[i];
		++index;
		++i;
	}

	while (j < rightArraySize) {
		array[index] = rightArray[j];
		++index;
		++j;
	}


	delete[] leftArray;
	delete[] rightArray;
}

