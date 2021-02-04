#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr);

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	fastio
	
	int N; cin >> N;
	ll r; cin >> r;
	
	for(int i = 2; i <= N; i++) {
		ll x;
		cin >> x;
		
		r = gcd(r, x);
	}

	ll ans = 0;
	for(ll i = 1; i * i <= r; i++) {
		if(r % i == 0) {
			ans++;
			if(r / i != i) ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}
