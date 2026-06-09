#include<iostream>
using namespace std;

class Queue{
    public:
    int front, rear;
    int capacity;
    int *arr;
    
    Queue(int size){
        arr = new int[size];
        front = rear = -1;
        capacity = size;
    }
    
    bool isEmpty(){
        return rear == -1;
    }
    
    bool isFull(){
        return rear == capacity-1;
    }
    
    void push(int x){
        if(isEmpty()){
            front = rear = 0;
            arr[rear] = x;
            cout<<x<<" Pushed Into Queue..."<<endl;
            return;
        }
        else if(isFull()){
            cout<<"Queue is FULL buddy"<<endl;
            return;
        }
        else{
            rear++;
            arr[rear] = x;
            cout<<x<<" Pushed Into Queue..."<<endl;
        }
    }
    
    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty Buddy..."<<endl;
            return;
        }
        else{
            front++;
            cout<<"Popped Element from Queue"<<endl;
            // if front overflows
            if(front > rear){
                front = rear = -1;
            }
        }
    }
    
    int getFront(){
        if(isEmpty()){
            cout<<"Queue is Empty Buddy...";
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int getSize(){
        // if(isFull()){
        //     cout<<"Queue is Full buddy..."<<endl;
        //     return 0;
        // }
        return rear-front+1;
    }
};

int main(){
    Queue q(5);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(5);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    
    
    cout<<"Front Element is : "<<q.getFront()<<endl;
    cout<<"Size of Queue : "<<q.getSize()<<endl;
}