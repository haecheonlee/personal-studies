#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	long long x; cin >> x;
	
	ll L = 1, R = x;
	for(ll i = 1; i * i <= x; i++) {
		if(x % i == 0) {
			if(gcd(x / i, i) != 1) continue;
			if(max(L, R) > max(x / i, i)) {
				L = min(x / i, i);
				R = max(x / i, i);
			}
		}
	}
	cout << L << " " << R << '\n';

	return 0;
}
