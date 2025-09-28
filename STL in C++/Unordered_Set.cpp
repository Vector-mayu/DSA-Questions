#include<iostream>
#include<unordered_set>
using namespace std;

// It contains only unique values (NO DUPLICATE)
// Search, Insert, Deletion only has O(1) Constant time
// It uses Hashing Technique to achieve it
// Also Provide unordered_multiset<type>var for Duplicate Values

int main()
{
	unordered_set<int>s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	s.insert(10);
	
	for(auto i = s.begin(); i!= s.end(); i++)
	{
		cout<<*i<<" ";
	}
}