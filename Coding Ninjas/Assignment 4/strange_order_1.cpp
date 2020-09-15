#include <iostream>
#include <bits/stdc++.h>
#define MAX 2000001

using namespace std;

vector<int> primes;

void createSieve()
{
	bool sieve[MAX];
	for(int i = 0; i < MAX; i++)
		sieve[i] = true;

	for(int i = 2; i < sqrt(MAX); i++)
	{
		if(sieve[i])
		{
			int temp = i;
			for(int j = pow(i,2); j < MAX; j = i*(++temp))
				sieve[j] = false;
		}
	}

	for(int i = 2; i < MAX; i++)
	{
		if(sieve[i])
			primes.push_back(i);
	}
}

void strangeOrder(int n)
{
	bool *marked = new bool[n+1];
	// bool *printed = new bool[n+1];
	for(int i = 0; i < n+1; i++)
	{
		marked[i] = false;
		// printed[i] = false;
	}

	while(n > 1)
	{
		int i = -1;
		int currN = n;
		if(marked[n])
		{
			n--;
			continue;
		}

		vector<int> printElt;

		while(currN > 1)
		{
			int currPrime;
			i++;
			while(currN % primes[i] != 0)
			{
				i++;
			}
			currPrime = primes[i];
			for(int elt = n; elt > 0; elt -= currPrime)
			{
				if(!marked[elt])
				{
					printElt.push_back(elt);
				}
			}

			while(currN % currPrime == 0)
			{
				currN /= currPrime;
			}
		}

		// sort(printElt.begin(), printElt.end(), greater<int>());

		for(int i = 0; i < printElt.size(); i++)
		{
			cout << printElt[i] << " ";
			marked[printElt[i]] = true;
		}
		cout << endl;

		printElt.clear();

		n--;
	}

	cout << "1";
}

int main()
{
	int n;
	createSieve();
	cin >> n;
	strangeOrder(n);
}