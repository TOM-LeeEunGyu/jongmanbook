#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
// ㅋㅋ
void josephus(int n, int k) {
	list<int> survivors;
	for (int i = 1; i <= n; i++)
		survivors.push_back(i);
	list<int>::iterator kill = survivors.begin();
	while (n > 2) {
		kill = survivors.erase(kill);
		if (kill == survivors.end()) kill = survivors.begin();
		n--;
		for (int i = 0; i < k - 1; i++) {
			kill++;
			if (kill == survivors.end()) kill = survivors.begin();
		}
	}
	cout << survivors.front() << " " << survivors.back() << endl;
}


int main() {
	int n, k;
	cin >> n >> k;
	josephus(n, k);
	return 0;
}
