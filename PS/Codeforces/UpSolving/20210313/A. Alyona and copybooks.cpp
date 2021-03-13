#include <iostream>

using namespace std;

void solve() {
	long long n, a, b, c; cin >> n >> a >> b >> c;
	long long k = ((n + 3) / 4 * 4) - n;

	if(k == 0) cout << 0 << '\n';
	else if(k == 1) cout << min(a, min(b + c, c * 3)) << '\n';
	else if(k == 2) cout << min(a * 2, min(b, c * 2)) << '\n';
	else if(k == 3) cout << min(c, min(a * 3, a + b)) << '\n';
	
}

int main() {
	solve();
	
	return 0;
}
