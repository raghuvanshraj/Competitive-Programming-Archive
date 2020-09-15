#include <bits/stdc++.h>
#define MAX 31

using namespace std;

class TrieNode
{
	TrieNode *left;
	TrieNode *right;

public:
	void insert(int n)
	{
		TrieNode *curr = this;
		for (int i = MAX; i >= 0; i--)
		{
			int b = ((n >> i) & 1);

			if (b == 0)
			{
				if (!curr->left)
				{
					curr->left = new TrieNode();
				}
				curr = curr->left;
			}
			else
			{
				if (!curr->right)
				{
					curr->right = new TrieNode();
				}
				curr = curr->right;
			}
		}
	}

	int _maxXOR(int n)
	{
		int curr_xor = 0;
		TrieNode *curr = this;
		for (int i = MAX; i >= 0; i--)
		{
			int b = ((n >> i) & 1);

			if ((b == 1 and curr->left) or (b == 0 and curr->right))
			{
				curr_xor += pow(2,i);
				curr = (b == 1) ? curr->left : curr->right;
			}
			else
			{
				curr = (b == 1) ? curr->right : curr->left;
			}
		}

		return curr_xor;
	}

	int maxXOR(int *arr, int n)
	{
		int max_xor = INT_MIN;
		for (int i = 0; i < n; ++i)
		{
			int curr_xor = this->_maxXOR(arr[i]);
			max_xor = (max_xor < curr_xor) ? curr_xor : max_xor;
		}

		return max_xor;
	}
};

int main(int argc, char const *argv[])
{
	int arr[] = {8,1,2,15,10,5};
	TrieNode *root = new TrieNode();
	for (int i = 0; i < 6; ++i)
	{
		root->insert(arr[i]);
	}

	cout << root->maxXOR(arr,6);

	return 0;
}