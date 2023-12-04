#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

bool wellMatched(const string& formula) {
	const string opening("({["), closing(")}]");
	stack<char> openStack;
	for (int i = 0; i < formula.size(); i++)
		if (opening.find(formula[i]) != -1)
			openStack.push(formula[i]);
		else {
			if (openStack.empty())return false;
			if (opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			openStack.pop();
		}
	return openStack.empty();
}

int main() {
	string formula;
	cin >> formula;
	if (wellMatched(formula))cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
