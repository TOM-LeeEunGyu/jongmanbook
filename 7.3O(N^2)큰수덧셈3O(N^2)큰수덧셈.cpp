#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void normalize(vector<int>& num) {
	num.push_back(0);
	for (int i = 0; i + 1 < num.size(); i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i+1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0)num.pop_back();
}


vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	normalize(c);
	return c;
}

int main() {

	vector<int> v1(105,1);
	vector<int> v2(200,1);
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(1);
	v2.push_back(8);
	v2.push_back(7);
	v2.push_back(6);
	v2.push_back(5);
	
	vector<int> v3 = multiply(v1, v2);
	
	reverse(v3.begin(), v3.end());
	vector<int>::iterator itor = v3.begin();
	for (; itor != v3.end(); itor++)
		cout << *itor;
}
