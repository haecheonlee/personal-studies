#include <iostream>

using namespace std;

void solve() {
	long long p, a, b, c; cin >> p >> a >> b >> c;
	
	long long aa = ((p + (a - 1)) / a * a) - p;
	long long bb = ((p + (b - 1)) / b * b) - p;
	long long cc = ((p + (c - 1)) / c * c) - p;
	
	cout << min(aa, min(bb, cc)) << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
