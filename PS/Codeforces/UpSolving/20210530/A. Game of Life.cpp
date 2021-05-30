/* reference: Rebro */

#include <iostream>

using namespace std;

void solve() {
	int N, M; cin >> N >> M;
	string s; cin >> s;
	
	M = min(N, M);
	string ans = "";
	
	for(int i = 0; i < N; i++) {
		if(s[i] == '1') {
			ans += '1';
		} else {
			bool chk1 = false, chk2 = false;
			for(int j = 1; j <= M; j++) {
				if(i - j >= 0 && s[i - j] == '1') chk1 = true;
				if(i + j < N && s[i + j] == '1') chk2 =true;
				
				if(chk1 && chk2) {
					ans += '0';
					break;
				} else if(chk1 || chk2) {
					ans += '1';
					break;
				}
			}
			if(!chk1 && !chk2) ans += '0';
		}
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
