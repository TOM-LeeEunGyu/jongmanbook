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
			num[i + 1] += num[i] / 10;
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

//a = a+b*(10^k)를 구현
void addTo(vector<int>& a, const vector<int>& b, int k) {
	int originalASize = a.size();
	if (a.size() < b.size() + k)
		a.resize(b.size() + k);
	a.push_back(0);

	for (int i = originalASize; i < a.size(); i++)
		a[i] = 0;
	for (int i = 0; i < b.size(); i++)
		a[i + k] += b[i];
	normalize(a);
}

//a = a-b를 구현, a>=b인 경우에만
void subForm(vector<int>& a, const vector<int>& b) {
	for (int i = 0; i < b.size(); i++) {
		a[i] -= b[i];
		normalize(a);
	}
}

//두 긴 정수간 곱 반환
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50)return multiply(a, b);

	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subForm(z1, z0);
	subForm(z1, z2);
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

int main() {

	vector<int> v1(300, 9);
	vector<int> v2(300, 9);

	vector<int> v3 = karatsuba(v1, v2);
	reverse(v3.begin(), v3.end());

	vector<int>::iterator itr = v3.begin();
	for (; itr != v3.end(); itr++)
		cout << *itr;

	return 0;
}
