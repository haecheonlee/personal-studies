/* reference: editorial */

#include <iostream>

using namespace std;

void solve() {
	long long a, b, n, m;
	cin >> a >> b >> n >> m;

	if(m <= min(a, b) && n + m <= a + b) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
