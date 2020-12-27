//#include <iostream>
#include "pch.h"
//using namespace std;
//
//////////////------------------------------------------------------------------------------------->///////////////
//
//
//void swapItems(int& a, int& b) {
//	int temp = b;
//	b = a;
//	a = temp;
//}
//
////-------SELECTION SORT-------//
//
//int findLargestIndex(const int* arr, int size) {
//	if (size == 0) return -1;
//
//	int maxInd = 0;
//
//	for (int i = 1; i < size; i++)
//		if (arr[i] > arr[maxInd])
//			maxInd = i;
//
//	return maxInd;
//}
//
//
//int* SelectionSort(int* arr, int size) {
//	if (size < 1) return NULL;
//	int maxInd;
//
//	for (int i = size - 1; i >= 0; i--) {
//		//get the index of max value
//		maxInd = findLargestIndex(arr, i + 1);
//		//if it's not in end, swap items at index i and maxInd
//		if (maxInd != i)
//			swapItems(arr[i], arr[maxInd]);
//	}
//	return arr;
//}
//
////-------BUBBLE SORT-------//
//
//int* BubbleSort(int* arr, int size) {
//	if (size < 1) return NULL;
//	bool noChanges = false;
//
//	//to mark the start of unsorted items
//	int startOfUnsorted = 0;
//
//	while (!noChanges && startOfUnsorted != size - 1) {
//		//if it remained true till end of inner loop, it means
//		//no further changes can happen, and hence I will exit the loop
//		noChanges = true;
//
//		for (int i = size - 1; i > startOfUnsorted; i--)
//			if (arr[i - 1] > arr[i]) {
//				swapItems(arr[i - 1], arr[i]);
//				noChanges = false;
//			}
//		startOfUnsorted++;
//	}
//	return arr;
//}
//
////-------INSERTION SORT-------//
//
//int* InsertionSort(int* arr, int size) {
//	if (size < 1) return NULL;
//	int valueTaken; //item at the hole
//	int hole;
//
//	for (int FirstUnsortedIndex = 1; FirstUnsortedIndex < size; FirstUnsortedIndex++) {
//		valueTaken = arr[FirstUnsortedIndex];
//		hole = FirstUnsortedIndex;
//		//as Long as the item at hole-1 is larger than the valueTaken,
//		//I shall put the value in the hole and decrement the hole
//		while (hole > 0 && arr[hole - 1] > valueTaken)
//			arr[hole--] = arr[hole - 1];
//
//		arr[hole] = valueTaken;
//	}
//	return arr;
//}
//
////-------MERGE SORT-------//----------------------------------->TOMORROWTOMORROWTOMORROWTOMORROW
////------------------------------------------------------------------------------------------------------------->
//int* MergeSort(int* arr, int size) {
//	if (size < 2) return NULL;
//
//	//Terminating condition
//	if (size == 2) {
//		if (arr[0] > arr[1])
//			swapItems(arr[0], arr[1]);
//		return arr;
//	}
//
//	//allocating the two arrays of left and right sides
//	int leftSize = size / 2;
//	int rightSize = size - leftSize;
//
//	int* left = new int[leftSize];
//	int* right = new int[rightSize];
//
//	//putting the items in both left and right arrays
//	for (int i = 0; i < leftSize; i++) {
//		left[i] = arr[i];
//		right[i] = arr[i + leftSize];
//	}
//
//	//if size of array is odd, the last element is put in right array
//	if (size % 2 != 0)
//		right[rightSize - 1] = arr[size - 1];
//
//	//Sorting left and right arrays
//	MergeSort(left, leftSize);
//	MergeSort(right, rightSize);
//
//	//Merging the two arrays back together
//	int leftInd = 0, rightInd = 0, mainInd = 0;
//
//	while (leftInd < leftSize && rightInd < rightSize) {
//		if (left[leftInd] < right[rightInd])
//			arr[mainInd++] = left[leftInd++];
//		else
//			arr[mainInd++] = right[rightInd++];
//	}
//
//	//probability says that one (only one) of the two arrays won't be all put in the main array
//	//these two loops put the rest of the items from them into the main array, already sorted
//
//	//if left still have elements in it
//	while (leftInd < leftSize)
//		arr[mainInd++] = left[leftInd++];
//
//	//if right still have elements in it
//	while (rightInd < rightSize)
//		arr[mainInd++] = right[rightInd++];
//
//	//Most importantly freeing this allocated memory in left and right arrays
//	//if not free, the SpaceComplexity of MergeSort would be n*Log(n)
//	delete[] left; delete[] right;
//	return arr;
//}
////------------------------------------------------------------------------------------------------------------->
////-------QUICK SORT-------//
//
//int MakePartation(int* arr, int size) {
//	if (size < 2) return 0;
//	//Relative to which I will make the partation
//	int pivot = arr[0];
//	//two iterators for left and right partitions
//	int L = 0, R = size;
//
//	while (true) {
//		while (arr[++L] < pivot) if (L == size - 1) break;
//		while (arr[--R] > pivot);
//		if (L >= R) break;
//		swapItems(arr[L], arr[R]);
//	}
//
//	//putting the pivot in its right place after the last lesser item
//	swapItems(arr[0], arr[R]);
//	return R;
//}
//
//int* QuickSort(int* arr, int size) {
//	if (size < 2) return NULL;
//	//make partation with random pivot (the item in end)
//	int partationIndex = MakePartation(arr, size);
//	//Quick Sort first half of the array
//	QuickSort(arr, partationIndex);
//	//Quick Sort second half of the array
//	QuickSort(arr + partationIndex + 1, size - partationIndex - 1);
//	return arr;
//}
////------------------------------------------------------------------------------------------------------------->
//int* QuickSort3(int arr[], int l, int r)
//{
//	int i = l - 1, j = r, p = l - 1, q = r; int v = arr[r];
//	if (r <= l) return NULL;
//	for (;;)
//	{
//		while (arr[++i] < v);
//		while (v < arr[--j]) if (j == l) break;
//		if (i >= j) break;
//		swapItems(arr[i], arr[j]);
//		if (arr[i] == v) { p++; swapItems(arr[p], arr[i]); }
//		if (v == arr[j]) { q--; swapItems(arr[j], arr[q]); }
//	}
//	swapItems(arr[i], arr[r]); j = i - 1; i = i + 1;
//	for (int k = l; k < p; k++, j--) swapItems(arr[k], arr[j]);
//	for (int k = r - 1; k > q; k--, i++) swapItems(arr[i], arr[k]);
//	QuickSort3(arr, l, j);
//	QuickSort3(arr, i, r);
//	return arr;
//}
////------------------------------------------------------------------------------------------------------------->
//
////-------SHELL SORT-------//
//int* ShellSort(int* arr, int size) {
//	if (size < 2) return NULL;
//	//the gap between each two items to swap, initiall by half of array size
//	int gap = size / 2;
//	//it holds the item to which I compare each "gap" indeces
//	int hold;
//	int current, walker;
//	
//	while (gap != 0) {
//		//set current to the fisrt gap index
//		current = gap;
//		while (current < size) {
//			//as long as I haven't finished sorting gaps in the array
//			//we hold a new item at position current
//			hold = arr[current];
//			//and start the walker at this index
//			walker = current;
//			while (walker >= gap && arr[walker - gap] > hold) {
//				//as long as the walker hasn't reached the gap, and the item
//				//before where I stand (walker-gap) is larger than the item held
//				//we put this item in walker index, and shift to the previos gap
//				arr[walker] = arr[walker - gap];
//				walker -= gap;
//			}
//			//put the held item in its correct position
//			arr[walker] = hold;
//			current++;
//		}
//		//dividing the gap to half its size
//		gap /= 2;
//	}
//	return arr;
//}
//
////Radwa Khattab @Copyrights *=* (consider it a duck face)