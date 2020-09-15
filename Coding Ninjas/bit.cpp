#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

struct Coder
{
	int speed;
	int accuracy;
	int index;
};

bool operator < (Coder a, Coder b)
{
	if (a.speed == b.speed)
	{
		return (a.accuracy < b.accuracy);
	}

	return (a.speed < b.speed);
}

void updateTree(int *tree, int i, int n)
{
	for (; i < n; i += (i & (-i)))
	{
		tree[i]++;
	}
}

int query(int *tree, int i)
{
	int ans = 0;
	for (; i > 0; i -= (i & (-i)))
	{
		ans += tree[i];
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Coder *coders = new Coder[n];
	int *tree = new int[MAX]();
	for (int i = 0; i < n; ++i)
	{
		cin >> coders[i].speed >> coders[i].accuracy;
		coders[i].index = i;
	}

	sort(coders, coders+n);

	int *output = new int[n];
	for (int i = 0; i < n;)
	{
		int endIndex = i;
		while (endIndex < n and 
				coders[endIndex].speed == coders[i].speed and 
				coders[endIndex].accuracy == coders[i].accuracy)
		{
			endIndex++;
		}

		for (int j = i; j < endIndex; ++j)
		{
			output[coders[j].index] = query(tree, coders[j].accuracy);	
		}
		for (int j = i; j < endIndex; ++j)
		{
			updateTree(tree, coders[j].accuracy, MAX);		
		}

		i = endIndex;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << output[i] << endl;
	}
	return 0;
}