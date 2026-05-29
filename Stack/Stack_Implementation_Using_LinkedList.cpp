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

class Stack{
    public:
    Node *index; // this will point top element address at top
    int size;
    
    Stack(){
        index = NULL;
        size = 0;
    }
    
    void push(int data){
        Node *temp = new Node(data);
        // this is used when we create LL with alot alot bigger size heap memory ends it becomes NULL
        if(!temp){
            cout<<"Stack Overflow...\n";
        }
        temp->next = index;
        index = temp;
        size++;
        cout<<data<<" Is pushed in stack...\n";
    }
    
    void pop(){
        if(index == NULL){
            cout<<"Stack Underflow\n";
        }
        else{
            cout<<index->data<<" Popped out of stack...\n";
            size--;
            Node * temp = index;
            index = index->next;
            delete temp;   
        }
    }
    
    int top(){
        return index->data;
    }
    
    int Size(){
        return size; 
    }
    
    bool empty(){
        return size == 0;
    }
};

int main(){
    Stack s;
    s.push(14);
    cout<<s.empty()<<endl;
    cout<<s.Size()<<endl;
    cout<<s.top()<<endl;
    s.push(21);
    s.push(23);
    s.pop();
    s.pop();
    s.pop();
}