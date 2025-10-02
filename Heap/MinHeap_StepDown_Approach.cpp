
	// IMPLEMENTATION OF minHeap (STEP-DOWN APPROACH)


// <<<<<<---- Time Complexity  ---->>>>>>>>
	// instead to O(nlogn) its O(N) here
	// Tailor Series Formula is used to calculate TC
	// GP formula which is a/(1-r) used


// <<<<<<---- Space Complexity  ---->>>>>>>>
	// Due to Recursion SC is O(logn)
	// Without Recursion O(1);


#include<iostream>
using namespace std;

void Heapify(int arr[], int index, int n)
{
	int largest = index;
	int left = 2*index+1;
	int right = 2*index+2;

	// If left is smaller
	if(left < n && arr[left] < arr[largest])
	largest = left;

	// If right is smaller
	if(right < n && arr[right] < arr[largest])
	largest = right;

	if(largest!= index) // When Largest is changed
	{
		swap(arr[index], arr[largest]);
		Heapify(arr, largest, n);
	}
}

void BuildMinHeap(int arr[], int n)
{
	for(int i=n/2-1; i>=0; i--) 
	// We used n/2-1 Bcuz of StepDown approach here we start from non leaf Nodes
	{
		Heapify(arr, i, n);
	}
}

void DisplayHeap(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{
	int arr[] = {12,32,25,67,1,44,30,18,23};
	BuildMinHeap(arr,9);
	DisplayHeap(arr, 9);
}