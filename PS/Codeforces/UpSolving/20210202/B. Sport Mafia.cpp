#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
	ll N, K; cin >> N >> K;
	
	ll ans = 0;
	ll L = 0, R = N;
	while(L <= R) {
		ll mid = (L + R) / 2;
		
		ll total = (mid * (mid + 1)) / 2;
		ll x = (N - mid);
		if(total - x == K) {
			cout << x << '\n';
			return;
		}

		if(total - x < K) L = mid + 1;
		else R = mid - 1;
	}
	cout << L << ' ' << R << '\n';
}

int main() {
	solve();

	return 0;
}
