//              Heap Sort 

// <<<<<<---- Time Complexity  ---->>>>>>>>
	// For all cases TC is O(nlogn) n = heapify and (n-1)logn = nlogn

// <<<<<<---- Space Complexity  ---->>>>>>>>
	// Due to Recursion SC is O(logn)
	// Without Recursion O(1);

//Implementation

#include<iostream>
using namespace std;

void Heapify(int arr[], int index, int n)
{
	int  largest = index;
	int left = 2*index+1;
	int right = 2*index+2;

	if(left < n && arr[left] > arr[largest])
	largest = left;
	if(right < n && arr[right] > arr[largest])
	largest = right;

	if(largest!= index)
	{
		swap(arr[index], arr[largest]);
		Heapify(arr, largest, n);
	}
}

void BuildMaxHeap(int arr[], int n)
{
	for(int i = n/2-1; i>=0 ; i--)
	{
		Heapify(arr, i, n);
	}
}

void HeapSort(int arr[], int n)
{
	for(int i = n-1; i>0; i--)
	{
		swap(arr[0], arr[i]);
		Heapify(arr, 0, i);
	}
}

void Display(int arr[], int n)
{
	for(int i=0; i < n ; i++)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{
	int arr[] = {2,33,45,67,89,23,90,43,12,30};
	BuildMaxHeap(arr, 10);
	HeapSort(arr, 10);
	Display(arr, 10);
}