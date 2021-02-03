#include <iostream>
#include <cstring>

using namespace std;

int N, a, b, c;
string s;

void solve() {
	cin >> N >> a >> b >> c;
	cin >> s;
	
	int win = 0;
	string ans(s.size(), '0');
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'R' && b) ans[i] = 'P', b--, win++;
		if(s[i] == 'P' && c) ans[i] = 'S', c--, win++;
		if(s[i] == 'S' && a) ans[i] = 'R', a--, win++;
	}
	
	for(int i = 0; i < s.size(); i++) {
		if(ans[i] == '0') {
			if(a) ans[i] = 'R', a--;
			else if(b) ans[i] = 'P', b--;
			else if(c) ans[i] = 'S', c--;
		}
	}
	
	if(win >= (N + 1) / 2) cout << "YES" << '\n' << ans << '\n';
	else cout << "NO" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
