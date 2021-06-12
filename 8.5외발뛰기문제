#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;
int board[10][10];
int n;
int cache[100][100];

bool jump(int y, int x) {  // 동적계획법 X
	if (y >= n || x >= n)return false;
	if (y == n - 1 && x == n - 1)return true;
	int jumpSize = board[y][x];
	return jump(y + jumpSize, x) || jump(y, x + jumpSize);

}


int jump2(int y, int x) {  // 동적계획법 O

	if (y >= n || x >= n)return 0;
	if (y == n - 1 && x == n - 1)return 1;
	int& ret = cache[y][x];
	if (ret != -1)return ret;
	int jumpSize = board[y][x];
	return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
}



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int init = board[0][0];
	
	if (jump(0,0))cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
	return 0;
}
