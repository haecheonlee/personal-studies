/* editorial */

#include <iostream>

using namespace std;

void solve() {
	long long x, y, k; cin >> x >> y >> k;
	
	long long ans = ((y * k) + k - 1 + (x - 2)) / (x - 1) + k;
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
