#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;
double cache[51][101][101];
int N, D, P, T;
int arr[51][51];
int Q[51];

double slove(int K, int day, double probability, int current) {
	if (day == D && current == K) return probability;
	if (day == D && current != K)return 0;
	if (day == D - 1 && arr[current][K] == 0) return 0;
	double& ret = cache[K][day][current];
	if (ret > -0.5)return ret;
	ret = 0;
	double link_num = 0;
	for (int i = 0; i < N; i++) {
		if (arr[current][i] == 1)
			link_num++;
	}
	probability *= (1 / link_num);
	for (int i = 0; i < N; i++) {
		if (arr[current][i] == 1)
			ret += slove(K, day + 1, probability, i);
	}
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> D >> P;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	cin >> T;
	for (int i = 0; i < T; i++)
		cin >> Q[i];
	for (int i = 0; i < T; i++)
		cout << slove(Q[i], 0, 1, P) << " ";
	return 0;
}
