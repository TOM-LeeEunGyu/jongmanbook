// 소풍 p155

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int MIN = numeric_limits<int>::min();

bool areFriends[10][10];

int countPairings(bool taken[10], int n) {
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[pairWith] = taken[firstFree] = true;
			ret += countPairings(taken, n);
			taken[pairWith] = taken[firstFree] = false;
		}
	}
	return ret;
}

int main()
{
	int c;
	cin >> c;

	while (c--) {

		int n, m;
		cin >> n >> m;
		int friends_X, friends_Y;

		for (int i = 0; i < m; i++) {
			cin >> friends_X >> friends_Y;
			areFriends[friends_X][friends_Y] = 1;
			areFriends[friends_Y][friends_X] = 1;
		}
		int count = 0;
		bool taken[10] = { false };
		count = countPairings(taken, n);
		cout << count << endl;
	}

	return 0;
}
