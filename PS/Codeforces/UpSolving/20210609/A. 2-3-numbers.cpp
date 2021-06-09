#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll go(ll x, ll d) {
	ll cnt = 0;
	
	while(x) {
		x /= d;
		cnt++;
	}
	
	return cnt;
}

int main() {
	ll l, r; cin >> l >> r;
	
	ll a = go(2000000000, 2), b = go(2000000000, 3);

	unordered_map<ll,int> cnt;
	ll ax = 1;
	for(int i = 0; i < a; i++) {
		ll bx = 1;
		for(int j = 0; j < b; j++) {
			ll sum = ax * bx;
			if(l <= sum && sum <= r) cnt[sum]++;
			bx *= 3;
		}
		ax *= 2;
		
	}
	cout << cnt.size() << '\n';

	return 0;
}
