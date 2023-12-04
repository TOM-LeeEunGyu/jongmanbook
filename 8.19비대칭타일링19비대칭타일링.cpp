#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
int N;
int MOD = 1000000007;

long long cache[101][101];
long long combination(int n, int r) {
	if (r == 0)return 1;
	if (n == r)return 1;
	long long& ret = cache[n][r];
	if (ret != -1)return ret;
	return ret = (combination(n - 1, r - 1) + combination(n - 1, r));
}

long long slove(int n) {
	long long sum = 0;
	for (int width = 0; width * 2 <= n; width++)
		sum += combination(n - width, width) % MOD;

	long long new_width, new_height;
	long long overlap=1;

	for (int width = 1; width * 2 <= n; width++) {
		if (n%2!=0 && width % 2 == 0) {
			new_width = width / 2;
			new_height = (n - 2 * width - 1) / 2;
			overlap += combination(new_width + new_height, new_width);
		}
		if (n % 2 == 0 && width % 2 != 0) {
			new_width = (width - 1) / 2;
			new_height = (n - 2 * width) / 2;
			overlap += combination(new_width + new_height, new_width);
		}
		if (n % 2 == 0 && width % 2 == 0) {
			new_width = width / 2;
			new_height = (n - 2 * width) / 2;
			overlap += combination(new_width + new_height, new_width);
		}
	}
	return (sum - overlap)%MOD;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	cout << slove(N) << endl;
	return 0;
}
