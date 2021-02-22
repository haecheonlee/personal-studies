#include <iostream>

using namespace std;

void solve() {
	string s; cin >> s;
	
	int p[4] {-1, -1, -1, -1};
	int ans = 0;
	for(int i = 0; i < s.size(); i++) {
		p[s[i] - '0'] = i;
		
		int L = min(p[1], min(p[2], p[3]));
		int R = max(p[1], max(p[2], p[3]));
		if(L == -1 || R == -1) continue;

		ans = (ans == 0 ? R - L + 1 : min(ans, R - L + 1));
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
