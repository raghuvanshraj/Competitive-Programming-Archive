#include <iostream>
#include <set>

using namespace std;

int main()
{
	int arr[] = {1,2,3,4,5,6};
	set<int> s;
	for(int i = 5; i >= 0; i--)
		s.insert(arr[i]);
	
	cout << s[2];
	//~ set<int>::iterator j;
	//~ for(j = s.begin(); j != s.end(); j++)
		//~ cout << *j << " ";
		
	return 0;
}
