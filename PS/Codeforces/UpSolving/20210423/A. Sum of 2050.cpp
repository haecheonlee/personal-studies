/* reference: editorial */

#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
	ll N; cin >> N;
	if(N % 2050) {
		cout << -1 << '\n';
	} else {
		N /= 2050;
		ll ans = 0;
		while(N) {
			ans += N % 10;
			N /= 10;
		}
		cout << ans << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
