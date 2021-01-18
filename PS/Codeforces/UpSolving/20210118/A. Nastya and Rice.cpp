/* reference: editorial */

#include <iostream>

using namespace std;

void solve() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	
	int L = n * (a - b), R = n * (a + b);
	if(R >= c - d && L <= c + d) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();
	
	return 0;
}
