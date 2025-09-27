
                        // List In C++ (Doubly LinkedList)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int>l;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    l.push_back(60);
    
    // Printing Values start to End 
    for(auto it = l.begin(); it!= l.end(); it++)
    {
        cout<<*it<<" ";
    }
    
    // Printing value In Reverse Order
    for(auto it = l.rbegin(); it!= l.rend(); it++)
    {
        cout<<*it<<" ";
    }
}

    