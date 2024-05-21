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
 * O() time complexity.
 */
void MergeSort(int array[], const int leftIndex, const int rightIndex);

/**
 * Helper function for MergeSort.
 */
void Merge(int array[], const int leftIndex, const int midIndex, const int rightIndex);
