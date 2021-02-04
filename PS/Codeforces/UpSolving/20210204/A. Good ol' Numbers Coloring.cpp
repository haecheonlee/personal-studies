#include <iostream>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void solve() {
	int a, b; cin >> a >> b;
	int r = gcd(a, b);
	
	cout << (r != 1 ? "Infinite" : "Finite") << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	
	return 0;
}
