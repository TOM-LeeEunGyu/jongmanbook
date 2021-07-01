#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
//coords : 현재 지배당하지 않는 점들의 목록
map<int, int> coords;
//새 점 (x,y)가 지배당하는지 확인 
bool isDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x); 
	//lower_bound함수의 경우 오른쪽 원소 중 기준 원소와 같거나 큰 값 중 가장 왼쪽에 있는 원소의 iterator값을 리턴한다.
	if (it == coords.end())return false; // 같거나 큰 원소가 없으면 false 반환
	return y < it->second;
}

//(x,y)에 지배당하는 점들을 트리에서 지움
void removeDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.begin()) return;
	it--;
	while (true) {
		if (it->second > y)break;
		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else {
			map<int, int>::iterator jt = it;
			jt--;
			coords.erase(it);
			it = jt;
		}
	}
}

int registered(int x, int y) {
	if (isDominated(x, y))return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}

int main() {
	int N;
	int sum = 0;
	cin >> N;
	int x[100000], y[100000];
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		sum += registered(x[i], y[i]);
	}
	cout << sum << endl;
	return 0;
}
