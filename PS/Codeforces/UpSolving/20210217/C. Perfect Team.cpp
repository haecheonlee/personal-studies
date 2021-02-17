/* editorial */

#include <iostream>

using namespace std;

void solve() {
	int c, m, x; cin >> c >> m >> x;
	int d = max(c, m) - min(c, m);
	
	x += d;
	if(c > m) c -= d;
	else m -= d;
	
	int ans = min(c, min(m, x));
	c -= ans;
	m -= ans;
	x -= ans;
	ans += (c + m) / 3;
	
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
