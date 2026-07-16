#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int element){
    if(!root)
    return new Node(element);
    
    // BST Creation 
    if(element < root->data){ // left side
        root->left = insert(root->left, element);
    }
    else{
        root->right = insert(root->right, element);
    }
    
    return root;
}

void inorder(Node *root){
    if(!root)
    return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int arr[] = {23,56,89,12,3,67,81};
    
    Node *root = NULL;
    for(int i=0; i<7; i++){
        root = insert(root, arr[i]);
    }
    cout<<"BST looks like :- ";
    inorder(root);
}