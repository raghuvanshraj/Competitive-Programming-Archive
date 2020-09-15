#include <bits/stdc++.h>
#define MAX 17

using namespace std;

class TrieNode
{
public:
	TrieNode *left;
	TrieNode *right;
	int leaves;

	TrieNode()
	{
		this->leaves = 0;
	}

	void insert(int n)
	{
		TrieNode *curr = this;
		for (int i = MAX; i >= 0; --i)
		{
			curr->leaves++;
			int b = ((n >> i) & 1);
			if (b == 1)
			{
				if (!curr->right)
				{
					curr->right = new TrieNode();
				}
				curr = curr->right;
			}
			else
			{
				if (!curr->left)
				{
					curr->left = new TrieNode();
				}
				curr = curr->left;
			}
		}
	}

	int query(int n,int k)
	{
		TrieNode *curr = this;
		int count = 0;
		for (int i = MAX; i >= 0; --i)
		{
			int bk = ((k >> i) & 1);
			int bn = ((n >> i) & 1);
			if (bk == 0)
			{
				if ((bn == 1 and !curr->right) or (bn == 0 and !curr->left))
				{
					return count;
				}
				else
				{
					if (bn == 1)
					{
						curr = curr->right;
					}
					else
					{
						curr = curr->left;
					}
				}
			}
			else
			{
				if (bn == 1 and curr->right)
				{
					count += curr->right->leaves;
				}
				else if (bn == 0 and curr->left)
				{
					count += curr->left->leaves;
				}

				if ((bn == 1 and !curr->left) or (bn == 0 and !curr->right))
				{
					return count;
				}
				else
				{
					if (bn == 1)
					{
						curr = curr->left;
					}
					else
					{
						curr = curr->right;
					}
				}
			}
		}

		return count;
	}
};

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,k;
		TrieNode *root = new TrieNode();
		root->insert(0);
		cin >> n >> k;
		int *arr = new int[n];
		int pre_xor = 0;
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			pre_xor ^= arr[i];

			count += root->query(pre_xor,k);
			root->insert(pre_xor);
		}

		cout << count << endl;
	}
	return 0;
}