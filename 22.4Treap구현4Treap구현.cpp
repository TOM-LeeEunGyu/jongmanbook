#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef int KeyType;
struct Node {
	KeyType key;
	int priority, size;
	Node *left, *right;
	Node(const KeyType& _Key) : key(_Key), priority(rand()),
		size(1), left(NULL), right(NULL) {
	}
	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }
	void calcSize() {
		size = 1;
		if (left)size += left->size;
		if (right)size += right->size;
	}
};


typedef pair<Node*, Node*> NodePair;

//2개의 트립으로 분리
NodePair split(Node* root, KeyType key) {
	if (root == NULL)return NodePair(NULL, NULL);
	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}

//root 루트로 하는 트립에 새 노드 삽입
Node* insert(Node* root, Node* node) {
	if (root == NULL)return;
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}

Node* merge(Node* a, Node* b) {
	if (a == NULL)return b;
	if (b == NULL)return a;
	if (a->priority < b->priority) {
		b->setLeft(merge(a, b->left));
		return b;
	}
	a->setRight(merge(a->right, b));
	return a;
}

//root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환
Node* erase(Node* root, KeyType key) {
	if (root == NULL)return root;
	if (root->key == key) {
		Node* ret = merge(root->left, root->right);
		delete root;
		return ret;
	}
	if (key < root->key)
		root->setLeft(erase(root->left, key));
	else
		root->setRight(erase(root->right, key));
	return root;
}

//트리의 k번째 원소를 찾는다.
Node* kth(Node* root, int k) {
	int leftSize = 0;
	if (root->left != NULL)leftSize = root->left->size;
	if (k <= leftSize)return kth(root->left, k);
	return kth(root->right, k - leftSize - 1);
}

//X보다 작은 원소의 수를 반환
int countLessThan(Node* root, KeyType key) {
	if (root == NULL)return 0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}


int main() {
	
	return 0;
}
