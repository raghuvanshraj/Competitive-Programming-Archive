#include <iostream>
#include <vector>
#include <set>

using namespace std;


vector<int> removeDuplicates(vector<int> input)
{
	set<int> s;
  	for(unsigned int i = 0; i < input.size(); i++)
      	s.insert(input[i]);
  
  	vector<int> output(s.begin(), s.end());
  	  
  	return output;
}

int main()
{
	int n;
	vector<int> input;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int elt;
		cin >> elt;
		input.push_back(elt);
	}
	vector<int> output = removeDuplicates(input);
	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}
