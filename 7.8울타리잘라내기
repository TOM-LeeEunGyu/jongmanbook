#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int slove(int left, int right, vector<int>& h) {
	if (left == right) return h[left];
	int mid = (left + right) / 2;
	
	int ret = min(slove(left, mid, h), slove(mid + 1, right, h));
	
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);

	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			hi++;
			height = min(height, h[hi]);
		}
		else {
			lo--;
			height = min(height, h[lo]);
		}
		ret = max(ret, height*(hi - lo + 1));
	}
	return ret;
}


int main() {

	int N;
	cin >> N;
	vector<int> h;
	int insert;
	for (int i = 0; i < N; i++) {
		cin >> insert;
		h.push_back(insert);
	}
	int square;
	square = slove(0, N-1, h);
	cout << square << endl;
	return 0;
}
