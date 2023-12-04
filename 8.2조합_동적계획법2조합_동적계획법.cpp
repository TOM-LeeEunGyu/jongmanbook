#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;
int cache[5][5] = { -1 };
int bino2(int n, int r) {
	if (r == 0 || n == r)return 1;
	if (cache[n][r] != -1) return cache[n][r];
	return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
}
int main() {

	memset(cache, -1, sizeof(cache));
	cout << bino2(4,2);
	return 0;
	
}
