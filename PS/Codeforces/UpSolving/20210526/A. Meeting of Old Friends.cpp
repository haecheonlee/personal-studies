#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll l1, r1, l2, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	
	ll s = max(l1, l2), e = min(r1, r2);
	if(s <= e) {
		ll ans = e - s + 1;
		if(s <= k && k <= e) ans--;
		cout << ans << '\n';
	} else {
		cout << 0 << '\n';
	}
	
	return 0;
}
