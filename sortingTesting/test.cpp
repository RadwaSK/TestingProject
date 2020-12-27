#include "pch.h"
#include"sorting.h"

namespace sort{
	template<typename T, size_t size>
	::testing::AssertionResult ArraysMatch(const T(&expected)[size],
		const T(&actual)[size]) {
		for (size_t i(0); i < size; ++i) {
			if (expected[i] != actual[i]) {
				return ::testing::AssertionFailure() << "array[" << i
					<< "] (" << actual[i] << ") != expected[" << i
					<< "] (" << expected[i] << ")";
			}
		}

		return ::testing::AssertionSuccess();
	}

	TEST(findLargestIndex, emptyArray) {

		int arr[5];
		sorting s = sorting();
		EXPECT_EQ(s.findLargestIndex(arr, 0), -1);
	}
	TEST(findLargestIndex, Size1) {
		sorting s = sorting();
		int arr3[5] = { 5 };
		EXPECT_EQ(s.findLargestIndex(arr3, 1), 0);
	}
	TEST(findLargestIndex, FirstIndex) {

		sorting s = sorting();
		int arr1[5] = { 5, 3, 2, 1 };
		EXPECT_EQ(s.findLargestIndex(arr1, 4), 0);
	}

	TEST(findLargestIndex, LastIndex) {
		sorting s = sorting();
		int arr2[5] = { 1, 3, 2, 5 };
		EXPECT_EQ(s.findLargestIndex(arr2, 4), 3);
	}
	TEST(SelectionSort, EmptyArray) {

		sorting s = sorting();

		int arr1[1];
		int arr1test[1];
		s.SelectionSort(arr1, 1);
		EXPECT_TRUE(ArraysMatch(arr1, arr1test));
	}
	TEST(SelectionSort, arrayOfSize1) {

		sorting s = sorting();

		int arr1[1] = { 4 };
		int arr1test[1] = { 4 };
		s.SelectionSort(arr1, 1);
		EXPECT_TRUE(ArraysMatch(arr1, arr1test));
	}

	TEST(SelectionSort, SortedArray) {

		sorting s = sorting();

		int arr2[4] = { 1, 2, 3, 4 };
		int arr2test[4] = { 1, 2, 3, 4 };
		s.SelectionSort(arr2, 4);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));
	}

	TEST(SelectionSort, UnSortedArray) {

		sorting s = sorting();

		int arr3[4] = { 4, 2, 1, 3 };
		int arr3test[4] = { 1, 2, 3, 4 };
		s.SelectionSort(arr3, 4);
		EXPECT_TRUE(ArraysMatch(arr3, arr3test));
	}
	TEST(BubbleSort, EmptyArray) {

		sorting s = sorting();

		int arr1[1];
		int arr1test[1];
		s.BubbleSort(arr1, 1);
		EXPECT_TRUE(ArraysMatch(arr1, arr1test));
	}
	TEST(BubbleSort, arrayOfSize1) {

		sorting s = sorting();

		int arr1[1] = { 4 };
		int arr1test[1] = { 4 };
		s.BubbleSort(arr1, 1);
		EXPECT_TRUE(ArraysMatch(arr1, arr1test));
	}

	TEST(BubbleSort, SortedArray) {

		sorting s = sorting();

		int arr2[4] = { 1, 2, 3, 4 };
		int arr2test[4] = { 1, 2, 3, 4 };
		s.BubbleSort(arr2, 4);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}

	TEST(BubbleSort, UnSortedArray) {

		sorting s = sorting();

		int arr3[4] = { 4, 2, 1, 3 };
		int arr3test[4] = { 1, 2, 3, 4 };
		s.BubbleSort(arr3, 4);
		EXPECT_TRUE(ArraysMatch(arr3, arr3test));
	}
	TEST(InsertionSort, EmptyArray) {

		sorting s = sorting();

		int arr1[1];
		int arr1test[1];
		s.InsertionSort(arr1, 1);
		EXPECT_TRUE(ArraysMatch(arr1, arr1test));
	}
	TEST(InsertionSort, arrayOfSize1) {

		sorting s = sorting();

		int arr1[1] = { 4 };
		int arr1test[1] = { 4 };
		s.InsertionSort(arr1, 1);
		EXPECT_TRUE(ArraysMatch(arr1, arr1test));
	}

	TEST(InsertionSort, SortedArray) {

		sorting s = sorting();

		int arr2[4] = { 1, 2, 3, 4 };
		int arr2test[4] = { 1, 2, 3, 4 };
		s.InsertionSort(arr2, 4);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}

	TEST(InsertionSort, UnSortedArray) {

		sorting s = sorting();

		int arr3[4] = { 4, 2, 1, 3 };
		int arr3test[4] = { 1, 2, 3, 4 };
		s.InsertionSort(arr3, 4);
		EXPECT_TRUE(ArraysMatch(arr3, arr3test));
	}

	TEST(MakePartation, arrayOfSize1) {

		sorting s = sorting();

		int arr1[1] = { 4 };
		EXPECT_EQ(s.MakePartation(arr1, 1), 0 );
	}

	TEST(MakePartation, PivotIsBiggest) {

		sorting s = sorting();

		int arr2[5] = { 5,2,3,1,4 };
		EXPECT_EQ(s.MakePartation(arr2, 5), 4);

	}

	TEST(MakePartation, PivotIsSmallest) {

		sorting s = sorting();

		int arr2[5] = { 1,2,6,5,4 };
		EXPECT_EQ(s.MakePartation(arr2, 5), 0);

	}

	TEST(MakePartation, PivotIsMedian) {

		sorting s = sorting();

		int arr2[6] = { 4,2,3,5,1,6 };
		EXPECT_EQ(s.MakePartation(arr2, 6), 3);

	}
	TEST(QuickSort, arrayOfSize1) {

		sorting s = sorting();

		int arr1[1] = { 4 };
		int arr1test[1] = { 4 };
		s.QuickSort(arr1, 1);
		EXPECT_TRUE(ArraysMatch(arr1, arr1test));
	}

	TEST(QuickSort, SortedArray) {

		sorting s = sorting();

		int arr2[4] = { 1, 2, 3, 4 };
		int arr2test[4] = { 1, 2, 3, 4 };
		s.QuickSort(arr2, 4);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}

	TEST(QuickSort, UnSortedArray) {

		sorting s = sorting();

		int arr3[4] = { 4, 2, 1, 3 };
		int arr3test[4] = { 1, 2, 3, 4 };
		s.QuickSort(arr3, 4);
		EXPECT_TRUE(ArraysMatch(arr3, arr3test));
	}

	TEST(QuickSort3, arrayOfSize1) {

		sorting s = sorting();

		int arr1[1] = { 4 };
		int arr1test[1] = { 4 };
		s.QuickSort3(arr1, 0, 0);
		EXPECT_TRUE(ArraysMatch(arr1, arr1test));
	}

	TEST(QuickSort3, SortedArray) {

		sorting s = sorting();

		int arr2[4] = { 1, 2, 3, 4 };
		int arr2test[4] = { 1, 2, 3, 4 };
		s.QuickSort3(arr2, 0, 3);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}

	TEST(QuickSort3, UnSortedArray1) {

		sorting s = sorting();

		int arr2[4] = { 4,2,3,1 };
		int arr2test[4] = { 1, 2, 3, 4 };
		s.QuickSort3(arr2, 0, 3);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}
	TEST(QuickSort3, UnSortedArray2) {

		sorting s = sorting();

		int arr2[6] = { 5,6,2,3,1,4 };
		int arr2test[6] = { 1, 2, 3, 4,5,6 };
		s.QuickSort3(arr2, 0, 5);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}
	TEST(QuickSort3, redundantValues) {

		sorting s = sorting();

		int arr2[5] = { 4,1,3,4,4 };
		int arr2test[5] = { 1,3,4,4,4 };
		s.QuickSort3(arr2, 0, 4);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}
	TEST(ShellSort, arrayOfSize1) {

		sorting s = sorting();

		int arr1[1] = { 4 };
		int arr1test[1] = { 4 };
		s.ShellSort(arr1, 1);
		EXPECT_TRUE(ArraysMatch(arr1, arr1test));
	}

	TEST(ShellSort, SortedArray) {

		sorting s = sorting();

		int arr2[4] = { 1, 2, 3, 4 };
		int arr2test[4] = { 1, 2, 3, 4 };
		s.ShellSort(arr2, 4);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}

	TEST(ShellSort, UnSortedArray) {

		sorting s = sorting();

		int arr2[3] = { 1,3,2 };
		int arr2test[3] = { 1, 2, 3 };
		s.ShellSort(arr2, 3);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}
	TEST(MergeSort, arrayOfSize1) {

		sorting s = sorting();

		int arr1[1] = { 4 };
		int arr1test[1] = { 4 };
		s.MergeSort(arr1, 1);
		EXPECT_TRUE(ArraysMatch(arr1, arr1test));
	}

	TEST(MergeSort, SortedArray) {

		sorting s = sorting();

		int arr2[5] = { 1, 2, 3, 4 ,5 };
		int arr2test[5] = { 1, 2, 3, 4, 5 };
		s.MergeSort(arr2, 5);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}

	TEST(MergeSort, UnSortedArray) {

		sorting s = sorting();

		int arr2[4] = { 3,5,4,1 };
		int arr2test[4] = { 1,3,4,5 };
		s.MergeSort(arr2, 4);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}
	TEST(MergeSort, DiscendinglySortedArray) {

		sorting s = sorting();

		int arr2[5] = { 5,4,3,2,1 };
		int arr2test[5] = { 1,2,3,4,5 };
		s.MergeSort(arr2, 5);
		EXPECT_TRUE(ArraysMatch(arr2, arr2test));

	}
}