#pragma once
class sorting
{
#pragma once
public:
	//Global functions to help
	void swapItems(int& a, int& b);

	//N.B.:: All these sorting functions, sort items ascendingly!!!
	/////////----------------------------------------------->//////////////////////////////////////
	//SELECTION SORT: complexity of ?(n^2), ?(n) swaps, Stable, Internal (O(1) space complexity)
	//Not adaptive (means that either data is nearly sorted or not, it behaves the same

	int findLargestIndex(const int* arr, int size);
	void SelectionSort(int* arr, int size);

	//BUBBLE SORT: complexity of O(n^2), Stable, Internal (O(1) extra space), Adaptive: O(n) when nearly sorted
	void BubbleSort(int* arr, int size);

	//INSERTION SORT: complxity of O(n^2) (but more efficient than SelectionSort and BubbleSort), Stable, very low overhead (not sure what it means)
	//Internal (O(1) extra space), Adaptive (O(n) time complexity when data is nearly sorted)

	void InsertionSort(int* arr, int size);

	//MERGE SORT: complexity of ?(n·log(n)), recursive, Stable, Not adaptive, doesn't require random access to data (Don't use RAM or Stack, just Heap)
	//External (takes 'n' extra space: ?(n) extra space for arrays .. ?(log(n)) extra space for linked lists)

	void MergeSort(int* arr, int size);

	//QUICK SORT: O(n2) time complexity (when array is sorted), but typically O(n·log(n)) like most of the times, recursice, Not Stable,
	//Not sure if it is called Adaptive or not, Internal (better than merge Sort in some cases because it is Internal not External)

	int MakePartation(int* arr, int size);

	void QuickSort(int* arr, int size);
	//Another Algorith for QuickSort, called QuickSort3 (3 stands for 3-way partitioning)

	void QuickSort3(int a[], int l, int r);

	//SHELL SORT: some references say O(n*sqrt(n)), others say O((n·log(n)) ^ 2) .. It varies depending on data composition
	//In Dr. Magda slides she says it can vary between O(n^3/2), O(n^7/2) or O(n^4/3) .. O(1) extra space, Not stable
	//Adaptive (means that its behaviour differs when data is nearly sorted, at such case time complexity = O(n·lg(n))

	void ShellSort(int* arr, int size);

};

