/**
 *    author:	vulkan
 *    created:	10.03.2020 06:16:43 PM
**/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build_tree(vector<int> tree, int pos) {
	int n = tree.size();
	if (n == 0 or pos >= n or tree[pos] == -1) {
		return NULL;
	}

	TreeNode *root = new TreeNode(tree[pos]);
	root->left = build_tree(tree, 2 * pos + 1);
	root->right = build_tree(tree, 2 * pos + 2);

	return root;
}

vector<int> postorderTraversal(TreeNode *root) {
	stack<TreeNode*> st;
	map<TreeNode*, bool> visited;
	vector<int> ans;
	if (root) {
		st.push(root);
	} else {
		return ans;
	}

	while (not st.empty()) {
		TreeNode *curr = st.top();
		bool flag = false;

		if (curr->right and not visited[curr->right]) {
			st.push(curr->right);
			flag = true;
		}

		if (curr->left and not visited[curr->left]) {
			st.push(curr->left);
			flag = true;
		}

		if (not flag or not (curr->left or curr->right)) {
			ans.push_back(curr->val);
			visited[curr] = true;
			st.pop();
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> tree(n);
	for (int i = 0; i < n; ++i) {
		cin >> tree[i];
	}

	TreeNode *root = build_tree(tree, 0);

	vector<int> traversal = postorderTraversal(root);
	for (int i = 0; i < traversal.size(); ++i) {
		cout << traversal[i] << ' ';
	}

	return 0;
}