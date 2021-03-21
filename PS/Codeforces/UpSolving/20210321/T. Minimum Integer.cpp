#include <iostream>

using namespace std;

void solve() {
	int l, r, d; cin >> l >> r >> d;
	if(d < l) cout << d << '\n';
	else cout << (r + d) / d * d << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
