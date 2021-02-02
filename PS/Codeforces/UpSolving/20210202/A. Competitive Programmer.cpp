#include <iostream>

using namespace std;

void solve() {
	string s; cin >> s;
	int zero = 0, even = 0, sum = 0;
	for(auto& c : s) {
		int d = c - '0';
		if(d == 0) zero++;
		if(d % 2 == 0) even++;
		sum += d;
	}
	cout << ((sum % 3 == 0) && zero && even >= 2 ? "red" : "cyan") << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
