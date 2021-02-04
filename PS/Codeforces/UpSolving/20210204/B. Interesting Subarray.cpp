/* editorial */

#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 1;

int a[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];

	for(int i = 2; i <= N; i++) {
		if(abs(a[i] - a[i - 1]) >= 2) {
			cout << "YES" << '\n';
			cout << i - 1 << ' ' << i << '\n';
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
