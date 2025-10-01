#include<iostream>
using namespace std;

class MaxHeap
{
	int *arr;
	int size; // Total Elements in Heap
	int total_size; // Total Size of Array

	public:
	MaxHeap(int n)
	{
		arr = new int[n];
		size = 0;
		total_size = n;
	}

	void Insert(int val)
	{
		if(size == total_size)
		{
			cout<<"Heap OverFlow\n";
			return;
		}
		
		arr[size] = val;
		int index = size;
		size++;

		// Compare it with Parents
		while(index > 0 && arr[(index-1)/2] < arr[index] ) // Here a child finds the parent Formu
		{
			swap(arr[index], arr[(index-1)/2]);
			index = (index-1)/2;
		} 
		
		cout<<arr[index]<<" Inserted in Heap"<<endl;
	}

	void display()
	{
		for(int i=0; i<size; i++)
		{
			cout<<arr[i]<<" ";
		}
	}
};

int main()
{
	MaxHeap h1(5);
	h1.Insert(14);
	h1.Insert(23);
	h1.Insert(18);
	h1.display();
}