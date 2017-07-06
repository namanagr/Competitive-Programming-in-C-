// This program covers the cocpets of vectors in c++
// Author : Naman Agrawal

// v.push_back -> appends an element to the array list.
// v.size() -> returns the size of the array list
// v.insert()
// v.erase()
// v.clear()
// v.empty()

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.insert(v.begin() + 2, 55); 
	for (unsigned int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	v.erase(v.begin());
	v.clear();
	cout << endl << v.empty();

	return 0;
}