/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	void _goodNodes(TreeNode *root, int &count, int max_val) {
		if (root == NULL) {
			return;
		}
		
		if (root->val >= max_val) {
			max_val = root->val;
			count++;
		}
		
		_goodNodes(root->left, count, max_val);
		_goodNodes(root->right, count, max_val);
	}
	
	int goodNodes(TreeNode* root) {
		int count = 0;
		_goodNodes(root, count, INT_MIN);
		
		return count;
	}
};