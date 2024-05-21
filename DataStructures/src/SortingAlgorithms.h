#pragma once

/**
 * O(n^2) time complexity.
 */
void BubbleSort(int array[], const int size);

/**
 * O(n^2) time complexity.
 */
void SelectionSort(int array[], const int size);

/**
 * O(n^2) time complexity.
 * For sorted or almost sorted data, it can behave like O(n).
 */
void InsertionSort(int array[], const int size);

/**
 * O(n log n) time complexity.
 * O(n) space complexity.
 */
void MergeSort(int array[], const int leftIndex, const int rightIndex);


void QuickSort(int array[], const int leftIndex, const int rightIndex);


/* HELPER FUNCTIONS */

/**
 * Helper function for QuickSort. Sorts all elements less than pivot to the left of pivot and all the ones greater than to the right of pivot.
 * Returns the index of the pivot.
 */
int Pivot(int array[], const int pivotIndex, const int endIndex);

/**
 * Helper function for MergeSort. Takes an array with two subordered arrays and merges them into the original array, in order.
 */
void Merge(int array[], const int leftIndex, const int midIndex, const int rightIndex);

/**
 * Helper function. Swaps the contents of the given indexes in the array.
 */
void Swap(int array[], const int firstIndex, const int secondIndex);


