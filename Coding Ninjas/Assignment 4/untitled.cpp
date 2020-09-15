#include <iostream>
#include <valarray>

using namespace std;

int main()
{
	valarray<int> input(5);
	for(int i = 0; i < 5; i++)
		cin >> input[i];

	return 0;
}