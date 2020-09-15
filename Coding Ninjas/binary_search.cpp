#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int i, int j)
{
	return i > j;
}

int main()
{
	int arr[] = {10, 45, -23, 0, 100, 23, 89};
	sort(arr, arr+7);
	for(int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;
	//cout << binary_search(arr, arr+7, 45);
	cout << lower_bound(arr, arr+7, 46)-arr << endl;
	cout << upper_bound(arr, arr+7, 46)-arr;
	
	return 0;
}
