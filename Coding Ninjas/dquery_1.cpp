#include <bits/stdc++.h>

using namespace std;

struct Event
{
	int start;
	int end;
	int index;
} query[2000000];

int arr[30001];
int BIT[30001];
int last[1000001];

bool operator < (Event a, Event b)
{
	return a.end < b.end;
}

void update(int index, int value, int n)
{
	for (int i = index; i < n+1; i += ((i) & (-i)))
	{
		BIT[i] += value;
	}
}

int value(int index)
{
	int total = 0;
	for (int i = index; i > 0; i -= ((i) & (-i)))
	{
		total += BIT[i];
	}

	return total;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	arr[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> query[i].start >> query[i].end;
		query[i].index = i;
	}

	sort(query, query+q);

	memset(BIT, 0, 30001 * sizeof(int));	
	memset(last, -1, 1000001 * sizeof(int));
	int total = 0;
	int k = 0;
	int ans[q];
	for (int i = 1; i <= n; ++i)
	{
		if (last[arr[i]] != -1)
		{
			update(last[arr[i]],-1,n);
		}
		else
		{
			total++;
		}

		update(i,1,n);
		last[arr[i]] = i;
		while (k < q and query[k].end == i)
		{
			ans[query[k].index] = total - value(query[k].start - 1);
			k++;
		}
	}

	for (int i = 0; i < q; ++i)
	{
		cout << ans[i] << endl;
	}
	return 0;
}