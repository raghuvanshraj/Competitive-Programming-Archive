#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	pair<int,char> p(1,'a');
	vector< pair<int,char> > v;
	unsigned int i;
	unsigned int j;
	for(i = 0, j = 'a'; i < 10; i++, j++)
		v.push_back(make_pair(i,j));
		
	vector< pair<int,char> >::iterator itr = v.find(make_pair(1,'a'));
	if(itr != v.end())
		cout << "found";
	else
		cout << "not found";
	//~ for(itr = v.begin(); itr != v.end(); itr++)
		//~ cout << itr->first << itr->second << " ";
	//~ for(unsigned int i = 0; i < v.size(); i++)
		//~ cout << v[i].first << v[i].second << " ";
		
	
	return 0;
}
