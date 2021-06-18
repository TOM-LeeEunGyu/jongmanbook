#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;
int arr[100];
int cache[100];
int N;

int lis(const vector<int>& A) {
	if (A.empty())return 0;
	int ret = 0;
	for (int i = 0; i < A.size(); i++) {
		vector<int> B;
		for (int j = i + 1; j < A.size(); j++)
			if (A[i] < A[j]) B.push_back(A[j]);
		ret = max(ret, 1 + lis(B));
	}
	return ret;
}

int lis2(int start) {
	int& ret = cache[start];
	if (ret != -1)return ret;
	ret = 1;
	for (int next = start + 1; next < N; next++) {
		if (arr[start] < arr[next])	
			ret = max(ret, lis2(next) + 1);
	}
}

int lis3(int start) {
	int& ret = cache[start + 1];
	if (ret != -1)return ret;
	ret = 1;
	for (int next = start + 1; next < N; next++)
		if (start == -1 || arr[start] < arr[next])
			ret = max(ret, lis3(next) + 1);
	return ret;
}

int main() {
	memset(cache,-1,sizeof(cache));
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << lis(A) << endl;
	return 0;
}
