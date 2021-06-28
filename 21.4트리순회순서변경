#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int N;
vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	const int N = preorder.size();
	if (preorder.empty())return;
	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	const int R = N - 1 - L;
	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	cout << root << " ";
}


int main() {
	cin >> N;
	vector<int> preorder;
	vector<int> inorder;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		preorder.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		inorder.push_back(temp);
	}
	printPostOrder(preorder, inorder);
	return 0;
}
