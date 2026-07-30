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
    
    void printHeap(){
        for(int i=0; i<size; i++){
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
}