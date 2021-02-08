#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ll a, b, x, y; cin >> a >> b >> x >> y;
	
	ll r = gcd(x, y);
	x /= r, y /= r;
	
	cout << min(a / x, b / y) << '\n';
	
	return 0;
}
