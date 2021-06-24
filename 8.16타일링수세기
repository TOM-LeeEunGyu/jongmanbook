#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
int N;

long long cache[101][101];
long long combination(int n, int r) {
	if (r == 0)return 1;
	if (n == r)return 1;
	long long& ret = cache[n][r];
	if (ret != -1)return ret;
	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}

long long slove(int n) {
	long long sum = 0;
	for (int width = 0; width * 2 < n; width++) 
		sum += combination(n - width, width);
	return sum;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cout << slove(N) << endl;
	return 0;
}

