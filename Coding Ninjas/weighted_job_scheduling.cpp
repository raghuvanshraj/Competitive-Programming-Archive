#include <iostream>
#include <algorithm>
using namespace std;
 
struct Job
{
    int start, finish, profit;
};
 
bool jobComparator(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}
 
int latestNonConflict(Job *arr, int i)
{
	int start = 0;
	int end = i-1;
	int mid;
	int ans = -1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid].finish <= arr[i].start)
		{
			ans = mid;
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}

	return ans;
}
 
int findMaxProfit(Job *arr, int n)
{
    sort(arr, arr+n, jobComparator);
 
    int *table = new int[n];
    table[0] = arr[0].profit;
 
    for (int i=1; i<n; i++)
    {
        int inclProf = arr[i].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l];
 
        table[i] = max(inclProf, table[i-1]);
    }
 
    int result = table[n-1];
    delete[] table;
 
    return result;
}
 
int main()
{
   	int n;
   	cin >> n;
   	Job *jobs = new Job[n]();
   	for (int i = 0; i < n; ++i)
   	{
   		cin >> jobs[i].start >> jobs[i].finish >> jobs[i].profit;
   	}
   	cout << findMaxProfit(jobs, n);
    return 0;
}