#include<iostream>
using namespace std;

class Node{
    public:
    Node *next;
    int data;
    
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    public:
    Node *front, *rear;
    int capacity;
    int count;
    
    Queue(int size){
        capacity = size;
        front = rear = NULL;
        count = 0;
    }
    
    bool isEmpty(){
        return front == NULL;
    }
    
    bool isFull(){
        return (count == capacity && count>0);
    }
    
    void push(int data){
        Node *temp = new Node(data);
        if(isFull()){
            cout<<"Queue is FULL..."<<endl;
            return;
        }
        if(isEmpty()){
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = rear->next;
        }
        count++;
        cout<<data<<" Pushed in to Queue"<<endl;
    }
    
    void pop(){
        if(isEmpty()){
            cout<<"Queue is empty..."<<endl;
            return;
        }
        else{
            Node *temp = front;
            front = front->next;
            if(front == NULL){
                rear = NULL;
            }
            count--;
            delete temp;
            cout<<"Popped Element from queue..."<<endl;
        }
    }
    
    int getFront(){
        if(isEmpty()){
            cout<<"Queue is empty..."<<endl;
            return 0;
        }
        return front->data;
    }
    
    int getSize(){
        return count;
    }
};

int main(){
    Queue q(2);
    q.push(14);
    q.push(5);
    q.push(23);
    cout<<q.getFront()<<endl;
    q.pop();
    q.pop();
    q.pop();
}