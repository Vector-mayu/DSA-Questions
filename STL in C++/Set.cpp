#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Only Unique values will be stored
// Stores values in Sorted order (Ascending)
// Insertion, Deletion and search operations have Logarithmic TIME
// (O(log n)), Making them fast for most use cases
// Generally Implemented using RBT(Reb Black Tree)
// We can Sort them in decending order using greater<type>

class Person
{
    public:
    string name;
    int age;
    
    bool operator < (const Person &other) const {
        return age > other.age; // Change the arrow for greater and lower
    }
};

int main()
{
    set<int>s;
    // Insertion
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    s.insert(60);
    
    // Printing Using For loop (Acending)
    for(auto i = s.begin(); i!= s.end(); i++)
    {
        cout<<*i<<" ";
    }
    
    // Printing in reverse Order (Decending)
    for(auto i = s.rbegin(); i!= s.rend(); i++)
    {
        cout<<*i<<" ";
    }
    
    // Find Any Valuein Set
    if(s.find(40)!=s.end()) // We can Also Use COUNT() for this
    {
        cout<<"Present"<<endl;
    }
    else
    {
        cout<<"Absent"<<endl;
    }
    
    // Count same as find
    if(s.count(70))
    {
        cout<<"Present"<<endl;
    }
    else
    {
        cout<<"Absent"<<endl;
    }
    
    // Deleting any value 
    s.erase(20);
    
    
    // Accessing using Class
    set<Person>p;
    Person p1, p2, p3, p4;
    p1.age = 19, p1.name = "Mayuresh";
    p2.age = 14, p2.name = "Shreyash";
    p3.age = 36, p3.name = "Virat";
    p4.age = 25, p4.name = "Rohit";
    
    p.insert(p1);
    p.insert(p2);
    p.insert(p3);
    p.insert(p4);
    
    for(auto i = p.begin(); i!=p.end(); i++)
    {
        cout<<(i->name)<<" "<<(i->age)<<endl;
    }
    
    
}