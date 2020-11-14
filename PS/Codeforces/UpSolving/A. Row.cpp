#include <iostream>

#define sz(x) (int)(x.size())

using namespace std;

int main() {
	int n;
	string s;

	cin >> n >> s;
	s = '0' + s + '0';

	bool ans = true;
	for(int i = 1; i < sz(s) - 1; i++) {
		if(s[i] == '0') {
			if(s[i - 1] == '0' && s[i + 1] == '0') ans = false;
		} else {
			if(s[i - 1] == '1' || s[i + 1] == '1') ans = false;
		}
	}
	cout << (ans ? "Yes" : "No");

	return 0;
}
