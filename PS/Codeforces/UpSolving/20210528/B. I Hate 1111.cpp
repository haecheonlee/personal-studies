/* reference: editorial */

#include <iostream>

using namespace std;

void solve() {
	int x; cin >> x;
	for(int i = 0; i <= x / 11; i++) {
		int L = 11 * i;
		int R = (x - L);
		
		if(R % 111 == 0) {
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
		
	return 0;
}
