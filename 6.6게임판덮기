#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int coverType[4][3][2] = {
	{ {0,0}, {1,0}, {0,1}},
	{ {0,0}, {0,1}, {1,1}},
	{ {0,0}, {1,0}, {1,1}},
	{ {0,0}, {1,0}, {1,-1}}
};

bool set(vector<vector<int>> &board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny<0 || ny>=board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1)  
			ok = false;
	}
	return ok;
}

// board[i][j]=1 -> 이미 덮였거나 검은 칸
// board[i][j]=0 -> 아직 덮이지 않은 칸
int cover(vector<vector<int>> &board) {
	//가장 위, 왼쪽에 덮이지 않은 칸을 찾음
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)break;
	}
	
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(board, y, x, type, 1))ret += cover(board);
		set(board, y, x, type, -1);
	}
	return ret;
}

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<int>> board;
	vector<int> board2;
	int count = 0;
	int temp;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> temp;
			if (temp == 0)count++;
			board2.push_back(temp);
			
		}
		board.push_back(board2);
		board2.clear();
	}
	if (count % 3 != 0) {cout << 0; return 0; }
	int result = 0;
	result += cover(board);
	cout << result << endl;
	return 0;

}
