/* editorial */

#include <iostream>

using namespace std;

void solve() {
	int a, b, c; cin >> a >> b >> c;

	int ms = max(0, (c + b - a + 2) / 2);	
	cout << max(c - ms + 1, 0) << '\n';
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
