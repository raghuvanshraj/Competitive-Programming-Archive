#include <bits/stdc++.h>
#define MAX 26

using namespace std;

class TrieNode {
public:
	int maxWeight;
	TrieNode** children;

	TrieNode() {
		maxWeight = -1;
		children = new TrieNode*[26]();
	}

	void insert(string s, int weight) {
		TrieNode *curr = this;
		for (int i = 0; i < s.size(); ++i)
		{
			curr->maxWeight = max(curr->maxWeight, weight);
			if (!(curr->children[s[i] - 'a']))
			{
				curr->children[s[i] - 'a'] = new TrieNode();
			}
			curr = curr->children[s[i] - 'a'];
		}
	}

	int query(string s) {
		TrieNode *curr = this;
		for (int i = 0; i < s.size(); ++i)
		{
			if (!(curr->children[s[i] - 'a']))
			{
				return -1;
			}
			curr = curr->children[s[i] - 'a'];
		}

		return curr->maxWeight;
	}
};

int main(int argc, char const *argv[]) {
	int n,q;
	cin >> n >> q;
	TrieNode *root = new TrieNode();
	for (int i = 0; i < n; ++i) {
		string word;
		int weight;
		cin >> word >> weight;
		root->insert(word, weight);
	}
	for (int i = 0; i < q; ++i) {
		string queryWord;
		cin >> queryWord;
		cout << root->query(queryWord) << endl;
	}
	return 0;
}