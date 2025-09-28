#include<iostream>
#include<unordered_map>
using namespace std;

// Unqiue Keys are Pressent, Duplicate keys are not allowed
// Not Neccesary that it should be in sorted form
// Uses Hashing for internal Implementation
// Insert, Search, Deletion is done in O(1) Constant time

int main()
{

	// Map Creation
	unordered_map<int,int>m;
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