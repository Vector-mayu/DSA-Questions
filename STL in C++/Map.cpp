#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// It stores Data in Key Value Pair
// It uses RBT(Red Black Tree) or AVL Tree for internal Implementation
// Insertion, Deletion, Search Has Logarithmic Time Complexity
// O(log n), Making them Fast for Most use Cases

int main()
{
	// Map Creation
	map<int,int>m;
	m.insert(make_pair(20, 14));
	m.insert(make_pair(30, 16));
	m.insert(make_pair(40, 18));
	m.insert(make_pair(50, 12));
	m.insert(make_pair(60, 0));
	m.insert(make_pair(70, 15));
	m[80] = 9; // Another way to insert or update any value

	// Delete any pair(ERASE)
	m.erase(80);

	for(auto i = m.begin(); i!= m.end(); i++)
	{
		cout<<i->first<<" "<<i->second<<endl;
	}


	 
}