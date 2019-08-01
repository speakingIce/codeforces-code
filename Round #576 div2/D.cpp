 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
class treeNode {
public:
	int minNum;
	int maxNum;
	int payout;
	int leftBound;
	int rightBound;
	treeNode* left;
	treeNode* right;
 
	treeNode() {
		minNum = -1; maxNum = -1; payout = -1; leftBound = -1; rightBound = -1; left = NULL; right = NULL;
	}
};
 
treeNode* buildTree(int* iniBalance, int l, int r) {
	treeNode* root = new treeNode;
	if (l == r) {
		root->minNum = iniBalance[l];
		root->maxNum = iniBalance[l];
		root->leftBound = l;
		root->rightBound = r;
		return root;
	}
	int mid = (l + r) / 2;
	root->left = buildTree(iniBalance, l, mid);
	root->right = buildTree(iniBalance, mid + 1, r);
	root->minNum = min(root->left->minNum, root->right->minNum);
	root->maxNum = max(root->left->maxNum, root->right->maxNum);
	root->leftBound = l;
	root->rightBound = r;
 
	return root;
}
 
void pushDown(treeNode* root) {
	if (root->left == NULL) {
		root->payout = -1;
		return;
	}
	if (root->payout != -1) {
		root->left->payout = max(root->left->payout, root->payout);
		root->right->payout = max(root->right->payout, root->payout);
		root->payout = -1;
	}
}
 
void changeBalance(treeNode* root, int i, int x) {
	pushDown(root);
	if (root->leftBound == root->rightBound && root->leftBound == i) {
		root->minNum = x;
		root->maxNum = x;
		return;
	}
	int mid = (root->leftBound + root->rightBound) / 2;
	if (i <= mid) {
		changeBalance(root->left, i, x);
	}
	else {
		changeBalance(root->right, i, x);
	}
	root->minNum = min(root->left->minNum, root->right->minNum);
	root->maxNum = max(root->left->maxNum, root->right->maxNum);
}
 
void payoutToAll(treeNode* root, int x) {
	if (root->minNum >= x) {
		return;
	}
	root->payout = max(root->payout, x);
}
 
int query(treeNode* root, int i) {
	if (root->leftBound == root->rightBound && root->leftBound == i) {
		return max(root->payout, root->minNum);
	}
	if (root->payout != -1) pushDown(root);
	int mid = (root->leftBound + root->rightBound) / 2;
	if (i <= mid)
		query(root->left, i);
	else
		query(root->right, i);
}
 
int main()
{
	int n;	cin >> n;
	int* iniBalance = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> iniBalance[i];
	}
 
	// build tree
	treeNode* root = buildTree(iniBalance, 0, n - 1);
 
	int q; cin >> q;
	while (q--) {
		int eventType; cin >> eventType;
		if (eventType == 1) {
			int p, x; cin >> p >> x; p--;
			// pthCitizen's balance change to p
			changeBalance(root, p, x);
		}
		else {
			int x; cin >> x;
			// payout to all possible citizens
			payoutToAll(root, x);
		}
	}
	for (int i = 0; i < n; i++) {
		// query the final balance of ith citizen and output
		cout << query(root, i) << " ";
	}
	cout << endl;
    return 0;
 
}
