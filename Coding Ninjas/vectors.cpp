#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

int main()
{
	vector<int> v;
	//cout << v.size();
	int arr[] = {1,2,3,4,5};
	v.assign(arr, arr+2);
	v.assign(arr, arr+3);
	
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	
	
	
	//cout << *itr;
	
	
	//~ if(find(v.begin(), v.end(), 2) != v.end())
		//~ cout << "Found";
	//~ else
		//~ cout << "Not found";
	//~ return 0;
}
