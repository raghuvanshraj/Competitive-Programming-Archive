#include <bits/stdc++.h> 

using namespace std;

struct Activity
{
	long start;
	long end;
};

bool comp(Activity a, Activity b)
{
	return a.end < b.end;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Activity *act = new Activity[n]();
	for (int i = 0; i < n; ++i)
	{
		cin >> act[i].start >> act[i].end;
	}
	sort(act, act+n, comp);

	int count = 1;
	int curr_end = act[0].end;
	int i = 1;
	while (i < n)
	{
		while (i < n and act[i].start < curr_end)
		{
			i++;
		}
		if (i == n)
		{
			break;
		}
		count++;
		curr_end = act[i].end;
	}
	cout << count;
	return 0;
}