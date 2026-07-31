#include<iostream>
using namespace std;

class MaxHeap{
    public:
    int *arr;
    int index;
    int size;
    
    MaxHeap(int n){
        arr = new int[n];
        index = 0;
        size = n;
    }
    
    void insert(int val){
        // if its the new element
        if(size == index){
            cout<<"Heap Overflow...";
            return;
        }
        
        // heap is empty
        if(index == 0){
            arr[index] = val;
            cout<<arr[index]<<" Inserted into Heap..."<<endl;
            index++;
            return;
        }
        
        arr[index] = val;
        int i = index;
        index++;
        
        // now lets find its OG position
        while(i>0 && arr[i] > arr[(i-1)/2]){
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
        
        cout<<arr[i]<<" Inserted into heap..."<<endl;
    }

    void Heapify(int i){
        // largest points the largest number across all 3 nums
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        // left < index means that we are not going out of bound
        if(left < index && arr[largest] < arr[left]){
            largest = left;
        }
        if(right < index && arr[largest] < arr[right]){
            largest = right;
        }
        
        // if there exists any largest in left or right then only swap
        if(largest != i){
            swap(arr[largest], arr[i]);
            Heapify(largest);
        }
    }

    void deleteHeap(){
        // if heap is empty
        if(index == 0){
            cout<<"Heap underflow...";
            return;
        }

        // if heap has only one element
        if(index == 1){
            cout<<arr[0]<<" is Deleted..."<<endl;
            index--;
            return;
        }

        // we only delete top element int the heap
        // if we have more than 1 element
        // we replace last element with 1st element 
        cout<<arr[0]<<" is Deleted...";
        arr[0] = arr[index-1];
        index--;

        // now we will find the right position for that swapped element
        Heapify(0);

    }
    
    void printHeap(){
        for(int i=0; i<index; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    MaxHeap h1(3);
    h1.insert(20);
    h1.insert(30);
    h1.insert(50);
    h1.printHeap();
    h1.insert(41);
    h1.deleteHeap();
    h1.printHeap();
}