#include <iostream>

using namespace std;

void solve() {
	long long a, b, c; cin >> a >> b >> c;
	if(a < b) swap(a, b);
	
	if(c == 0) {
		cout << (a == b ? "YES" : "NO") << '\n';
	} else {
		long long diff = a - b;
		long long rem = (diff + b - 1) / b;
		cout << (rem <= c ? "YES" : "NO") << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
