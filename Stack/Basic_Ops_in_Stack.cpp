#include<iostream>
using namespace std;

class Stack{
    public:
    int arr[100];
    int index;
    
    Stack(){
        index = -1;
    }
    
    void push(int val){
        if(index == 99){
            cout<<"Stack Overflow\n";
        }
        else{
            index++;
            arr[index] = val;
            cout<<val<<" is Pushed in Stack\n";
        }
    }
    
    void pop(){
        if(index == -1){
            cout<<"Stack Underflow\n";
        }
        else{
            cout<<arr[index]<<" Popped from the stack\n";
            index--;
        }
    }
    
    int top() {
    if(index == -1){
        cout << "Stack is Empty\n";
        return -1;
    }
    return arr[index];
}
    
    bool empty(){
        return index == -1;
    }
    
    int size(){
        return index+1;
    }
};

int main(){
    Stack s;
    s.pop();
    s.push(100);
    cout<< s.empty() <<endl;
    cout<< s.top() <<endl;
    cout<< s.size() <<endl;
    s.pop();
}