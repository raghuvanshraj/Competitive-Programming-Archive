#include <bits/stdc++.h>
#define MAX 26

using namespace std;

class TrieNode {
public:
    vector<string> availableWords;
    TrieNode** children;

    TrieNode()
    {
        children = new TrieNode*[26]();
    }

    void insert(string s)
    {
        TrieNode *curr = this;
        for (int i = 0; i < s.size(); ++i) {
            curr->availableWords.push_back(s);
            if (!(curr->children[s[i] - 'a'])) {
                curr->children[s[i] - 'a'] = new TrieNode();
            }
            curr = curr->children[s[i] - 'a'];
        }
        curr->availableWords.push_back(s);
    }

    void query(string s) 
    {
        TrieNode *curr = this;
        for (int i = 0; i < s.size(); ++i) {
            if (!(curr->children[s[i] - 'a'])) {
                this->insert(s);
                cout << "No suggestions\n";
                return;
            }
            curr = curr->children[s[i] - 'a'];
        }
        sort(curr->availableWords.begin(), curr->availableWords.end());
        for (int i = 0; i < curr->availableWords.size(); ++i) {
            cout << curr->availableWords[i] << endl;
        }
    }
};

int main(int argc, char const* argv[])
{
    int n,q;
    cin >> n;
    TrieNode *root = new TrieNode();
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        root->insert(word);
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        string queryWord;
        cin >> queryWord;
        root->query(queryWord);
    }
    return 0;
}