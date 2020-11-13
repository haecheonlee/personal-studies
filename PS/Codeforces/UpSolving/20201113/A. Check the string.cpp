#include <iostream>
#include <vector>

#define sz(x) (int)(x.size())

using namespace std;

vector<int> a, b, c;

bool is_contiguous(vector<int>& x) {
	for(int i = 0; i < sz(x) - 1; i++) {
		if(x[i + 1] - x[i] > 1) return false;
	}

	return true;
}

bool is_position_good() {
	if(sz(a) && sz(b) && sz(c)) {
		if(a[0] > b[0] || c[0] < a[0] || c[0] < b[0]) return false;
	}

	if(sz(a) && sz(c)) {
		if(a[0] > c[0]) return false;
	}

	if(sz(b) && sz(c)) {
		if(b[0] > c[0]) return false;
	}

	return true;
}

bool is_good() {
	return is_position_good() && is_contiguous(a) && is_contiguous(b) && is_contiguous(c);
}

int main() {
	string s;
	cin >> s;

	for(int i = 0; i < sz(s); i++) {
		if(s[i] == 'a') a.push_back(i);
		else if(s[i] == 'b') b.push_back(i);
		else c.push_back(i);
	}

	if((sz(a) == sz(c) || sz(b) == sz(c)) && (sz(a) && sz(b))) {
		cout << (is_good() ? "YES" : "NO");
	} else {
		cout << "NO";
	}

	return 0;
}
