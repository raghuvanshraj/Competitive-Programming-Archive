#include <bits/stdc++.h>
#define MAX 31

using namespace std;

class TrieNode
{
	int value;
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
		curr->value = n;
	}

	int query(int n)
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
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *arr = new int[n]();
	int result = INT_MIN;
	int pre_xor = 0;
	TrieNode *root = new TrieNode();
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		pre_xor ^= arr[i];
		root->insert(pre_xor);

		result = max(result, root->query(pre_xor));
	}

	cout << result;

	return 0;
}