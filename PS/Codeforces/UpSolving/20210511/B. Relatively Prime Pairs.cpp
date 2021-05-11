#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll l, r; cin >> l >> r;
	
	ll L = (r - l + 1);
	if(L % 2 == 0) {
		cout << "YES" << '\n';
		for(ll i = l; i <= r; i += 2) cout << i << ' ' << i + 1 << '\n';
	} else {
		cout << "NO" << '\n';
	}
	
	return 0;
}
