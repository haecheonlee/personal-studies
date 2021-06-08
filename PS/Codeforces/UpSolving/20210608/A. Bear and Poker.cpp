/* editorial */

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int N; cin >> N;
	ll a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	ll x = a[0];
	for(int i = 1; i < N; i++) x = gcd(a[i], x);
	
	while(x % 2 == 0) x /= 2;
	while(x % 3 == 0) x /= 3;
	
	for(int i = 0; i < N; i++) {
		int two = 1, three = 1;
		while(a[i] % (two * 2) == 0) two *= 2;
		while(a[i] % (three * 3) == 0) three *= 3;
		if(x * two * three != a[i]) {
			cout << "No" << '\n';
			return 0;
		}
	}
	cout << "Yes" << '\n';

	return 0;
}
