#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll x, y, z; cin >> x >> y >> z;
	
	ll k = (x + y) / z, kk = (x / z) + (y / z);

	if(k == kk) cout << k << ' ' << 0 << '\n';
	else cout << k << ' ' << min(z - x % z, z - y % z) << '\n';

	return 0;
}
