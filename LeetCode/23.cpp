/**
 *    author:	vulkan
 *    created:	07.03.2020 06:10:35 PM
**/
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_ll(vector<int> &curr_vector) {
	ListNode *temp = new ListNode(curr_vector[0]);
	ListNode *head = temp;
	for (int i = 1; i < curr_vector.size(); ++i) {
		temp->next = new ListNode(curr_vector[i]);
		temp = temp->next;
	}

	return head;
}

static bool comp(ListNode *a, ListNode *b) {
	return a->val > b->val;
}

ListNode* mergeKLists(vector<ListNode*> &lists) {
	priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> min_heap(comp);
	int k = lists.size();
	for (int i = 0; i < k; ++i) {
		if (lists[i]) {
			min_heap.push(lists[i]);
		}
	}

	if (min_heap.empty()) {
		return NULL;
	}

	ListNode *curr = min_heap.top();
	min_heap.pop();

	ListNode *res = new ListNode(curr->val);
	ListNode *temp = res;

	if (curr->next) {
		min_heap.push(curr->next);
	}

	while (not min_heap.empty()) {
		curr = min_heap.top();
		min_heap.pop();
		if (curr->next) {
			min_heap.push(curr->next);
		}

		temp->next = new ListNode(curr->val);
		temp = temp->next;
	}

	return res;
}

int main(int argc, char const *argv[]) {
	int k;
	cin >> k;
	vector<ListNode*> lists(k);

	string input;
	getline(cin, input);
	for (int i = 0; i < k; ++i) {
		getline(cin, input);

		int n = input.size();
		vector<int> curr_vector(n / 2 + 1);
		int j = 0;
		for (int i = 0; i < n; i += 2) {
			curr_vector[j++] = input[i] - '0';
		}

		lists[i] = create_ll(curr_vector);
	}

	ListNode *merged_list = mergeKLists(lists);
	ListNode *curr = merged_list;
	while (curr) {
		cout << curr->val << ' ';
		curr = curr->next;
	}

	// for (int i = 0; i < k; ++i) {
	// 	ListNode *curr_list = lists[i];
	// 	while (curr_list) {
	// 		cout << curr_list->val << ' ';
	// 		curr_list = curr_list->next;
	// 	}

	// 	cout << endl;
	// }

	return 0;
}