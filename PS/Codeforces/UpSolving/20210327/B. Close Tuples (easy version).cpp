#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 10;

int a[MAX_N];
ll cnt[MAX_N];

ll ncr(ll x) {
	ll k = 1;
	ll L = max(0LL, x - 2);
	for(ll i = x; i >= L; i--) k *= i;
	return k / 6;
}

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cnt[i] = 0;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		cnt[a[i]]++;	
	}
	
	ll ans = 0;	
	for(int i = 1; i <= N - 2; i++) {
		ll x = cnt[i], y = cnt[i + 1], z = cnt[i + 2];
		if(i > 1) ans -= ncr(x + y);
		ans += ncr(x + y + z);
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
