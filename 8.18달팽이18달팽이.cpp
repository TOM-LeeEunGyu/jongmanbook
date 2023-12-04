#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#include<math.h>
using namespace std;
int n, m;
int cache[1000][2001];

int climb(int days, int climbed) {
	if (days == n)return climbed >= m ? 1 : 0;
	int& ret = cache[days][climbed]; 
	if (ret != -1)return ret;
	return ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);

}


int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	double answer = climb(0, 0) / pow(2, n);
	cout << answer << endl;
	return 0;
}
