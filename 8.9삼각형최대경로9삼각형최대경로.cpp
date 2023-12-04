#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;
int arr[100][100];
int cache[100][100];
int slove(int height, int y, int x) {
	if (y == height - 1)return arr[y][x];
	int& ret = cache[y][x];
	if (ret != -1)return ret;
	return ret = max(slove(height, y + 1, x), slove(height, y + 1, x + 1)) + arr[y][x];

}

int main() {
	memset(cache, -1, sizeof(cache));
	int height;
	cin >> height;
	for (int i = 0; i < height; i++)
		for (int j = 0; j <= i; j++)
			cin >> arr[i][j];
	
	cout << slove(height, 0, 0) << endl;

}
