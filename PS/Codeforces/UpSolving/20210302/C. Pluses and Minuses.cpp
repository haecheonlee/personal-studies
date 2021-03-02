/* editorial */

#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
	string s; cin >> s;
	
	ll ans = s.size(), cur = 0, k = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '+') cur++;
		else cur--;
		
		if(cur < k) {
			k = cur;
			ans += i + 1;
		}
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
