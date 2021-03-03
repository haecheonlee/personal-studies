/* editorial */

#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
	ll n, g, b; cin >> n >> g >> b;
	
	ll needG = (n + 1) / 2;
	ll G = (needG / g) * (g + b);
	G += (needG % g == 0LL ? -b : needG % g);
	cout << max(n, G) << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
