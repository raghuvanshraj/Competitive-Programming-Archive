#include <bits/stdc++.h>
#define MAX 100001

using namespace std;
typedef long long ll;

struct Worker
{
	ll speed = INT_MIN;
	ll wage = 0;
};

int main(int argc, char const *argv[])
{
	ll n,d;
	cin >> n >> d;
	Worker *workers = new Worker[MAX]();
	for (int i = 0; i < n; ++i)
	{
		ll index, speed, wage;
		cin >> index >> wage >> speed;
		if (speed > workers[index].speed)
		{
			workers[index].speed = speed;
			workers[index].wage = wage;
		}
	}
	
	ll left = d;
	ll currWorker = -1;
	ll totalCost = 0;
	for (int i = 0; i < MAX; ++i)
	{
		left -= workers[currWorker].speed;
		if (left <= 0)
		{
			break;
		}
		if (workers[i].wage != 0)
		{
			if (currWorker == -1)
			{
				currWorker = i;
				totalCost += workers[i].wage;
			}
			else if (workers[i].speed > workers[currWorker].speed)
			{
				// ll workDone = (i - currWorker) * workers[currWorker].speed;
				// left -= workDone;
				// if (left <= 0)
				// {
				// 	break;
				// }
				// else
				// {
					totalCost += workers[i].wage;
					currWorker = i;
				// }
			}
		}
	}

	cout << totalCost;

	return 0;
}