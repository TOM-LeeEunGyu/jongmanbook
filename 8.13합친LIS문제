#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
const long long NEGINF = -2100000000;
using namespace std;
int arrN[101];
int arrM[101];
int N, M;
int cache[101][101];

//나의코드
int sumLis(int indexN, int indexM) {
	if (indexN == N)return M - indexM;
	else if (indexM == M)return N - indexN;
	else if (indexN == N && indexM == M)return 0;

	int& ret = cache[indexN][indexM];
	if (ret != -1)return cache[indexN][indexM];
	ret = 1;
	int current;
	if (arrN[indexN] < arrM[indexM]) {
		current = arrN[indexN];
		ret += sumLis(indexN + 1, indexM);
	}
	else if (arrN[indexN] > arrM[indexM]) {
		current = arrM[indexM];
		ret += sumLis(indexN, indexM + 1);
	}
	else {
		current = arrN[indexN];
		ret += sumLis(indexN + 1, indexM + 1);
	}
	return ret;
}

int jlis(int indexN, int indexM) {
	int& ret = cache[indexN + 1][indexM + 1];
	if (ret != -1)return ret;
	ret = 2;
	long long a = (indexN == -1 ? NEGINF : arrN[indexN]);
	long long b = (indexM == -1 ? NEGINF : arrM[indexM]);
	long long maxElement = max(a, b);
	//다음 원소를 찾음
	for (int nextN = indexN + 1; nextN < N; nextN++)
		if (maxElement < arrN[nextN])
			ret = max(ret, jlis(nextN, indexM) + 1);
	for (int nextM = indexM + 1; nextM < N; nextM++)
		if (maxElement < arrM[nextM])
			ret = max(ret, jlis(indexN, nextM) + 1);
	return ret;
}


int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arrN[i];
	for (int i = 0; i < M; i++)
		cin >> arrM[i];
	sort(arrN, arrN + N);
	sort(arrM, arrM + M);
	cout << sumLis(0, 0) << endl;
	cout << jlis(0, 0) << endl;
	return 0;
}
