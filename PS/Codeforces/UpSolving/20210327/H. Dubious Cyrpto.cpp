#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
	ll l, r, m; cin >> l >> r >> m;
	
	ll k = r - l;
	for(ll i = l; i <= r; i++) {
		ll L = m - ((m / i) * i), R = (m + i - 1) / i * i - m;
		if(L <= k && m - ((l + L) - l) != 0) {
			cout << i << ' ' << l + L << ' ' << l << '\n';
			break;
		} 
		
		if(R <= k) {
			cout << i << ' ' << l << ' ' << l + R << '\n';
			break;
		}
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
