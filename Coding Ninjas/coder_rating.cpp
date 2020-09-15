#include <bits/stdc++.h>

using namespace std;

struct Coder
{
	int a = 0;
	int h = 0;
	int index = -1;
};

struct Ans
{
	int value = 0;
	int index = -1;
};

bool compareCoder(Coder x, Coder y)
{
	if (x.a == y.a)
	{
		return x.h < y.h;
	}
	
	return x.a < y.a;
}

bool compareAns(Ans x, Ans y)
{
	return x.index < y.index;
}

void update(int *BIT, Coder *coders, int index, Coder currCoder, int n)
{
	for (int i = index; i > 0; i -= ((i) & (-i)))
	{
		int start = i - ((i) & (-i)) + 1;
		int end = i;
		for (int i = start; i < end+1; ++i)
		{
			if (coders[i].h < currCoder.h)
			{
				BIT[index]++;
			}
			else if (coders[i].h == currCoder.h)
			{
				if (coders[i].a < currCoder.a)
				{
					BIT[index]++;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Coder *coders = new Coder[n+1]();
	int *BIT = new int[n+1]();
	for (int i = 1; i < n+1; ++i)
	{
		cin >> coders[i].a >> coders[i].h;
		coders[i].index = i;
	}
	sort(coders, coders + n+1, compareCoder);
	for (int i = 1; i < n+1; ++i)
	{
		update(BIT, coders, i, coders[i], n);
	}
	Ans *ans = new Ans[n+1]();
	for (int i = 1; i < n+1; ++i)
	{
		ans[i].value = BIT[i];
		ans[i].index = coders[i].index;
	}
	sort(ans, ans + n+1, compareAns);
	for (int i = 1; i < n+1; ++i)
	{
		cout << ans[i].value << endl;
	}
	return 0;
}