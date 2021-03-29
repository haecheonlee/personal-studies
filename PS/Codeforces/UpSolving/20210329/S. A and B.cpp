#include <iostream>

using namespace std;

void solve() {
	int a, b; cin >> a >> b;
	if(a == b) {
		cout << 0 << '\n';
	} else {
		int d = abs(a - b), sum = 0;
		for(int k = 1; k <= 50000; k++) {
			sum += k;
			if(sum >= d && (sum - d) % 2 == 0) {
				cout << k << '\n';
				return;
			}
		}
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
