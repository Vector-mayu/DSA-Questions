#include<iostream>
using namespace std;

class Node{
    public:
    
    int val;
    Node *prev, *next;
    
    Node(int data){
        val = data;
        prev = next = NULL;
    }
};

int main(){
    int arr[5] = {1,2,3,4,5};
    Node *head = NULL;
    
    Node *tail = head;
    for(int i=0; i<5; i++){
        if(!head){
            head = new Node(arr[i]);
            tail = head;
        }
        else{
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }
    }
    
    Node *temp = head;
    for(int i=0; i<5; i++){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    
    cout<<endl;
    
    temp = head;
    temp = temp->next->next;
    
    // insertion in middle 
    Node *newNode = new Node(23);
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    temp->next->prev = temp;
    
    temp = head;
    for(int i=0; i<6; i++){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    return 0;
}


