#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int>l1;
    
    l1.push_back(21);
    l1.push_back(12);
    l1.push_back(57);
    l1.push_back(75);
    l1.push_back(14);
    
    for(auto x: l1){
        cout<<x<<" ";
    }
    
    cout<<endl;
    
    // lets use iterator now
    for(auto it = l1.begin(); it != l1.end(); it++){
        cout<<*it<<" ";
    }
}