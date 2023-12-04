#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
int n;
int cache[100][100];
int countCache[100][100];
int triangle[100][100];

int path(int y, int x) {
	if (y == n - 1)return triangle[y][x];
	int& ret = cache[y][x];
	if (ret != -1)return ret;
	return ret = max(path(y + 1, x), path(y + 1, x + 1) + triangle[y][x]);
}

int count(int y, int x) {
	if (y == n - 1)return 1;
	int& ret = countCache[y][x];
	if (ret != -1)return ret;
	ret = 0;
	if (path(y + 1, x + 1) >= path(y + 1, x)) ret += count(y + 1, x + 1);
	if (path(y + 1, x + 1) <= path(y + 1, x)) ret += count(y + 1, x);
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	memset(countCache, -1, sizeof(countCache));
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> triangle[i][j];
	cout << count(0,0) << endl;
	return 0;
}
