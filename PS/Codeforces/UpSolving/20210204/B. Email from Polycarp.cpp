#include <iostream>

using namespace std;

void solve() {	
	string s, ss;
	cin >> s >> ss;

	int L = 0, chk = 1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != s[i + 1]) {
			if(s[i] == ss[L]) while(s[i] == ss[L]) L++;
			else { chk = 0; break; }
		} else {
			if(s[i] == ss[L]) L++;
			else { chk = 0; break; }
		}
	}
	
	cout << (chk && L == ss.size() ? "YES" : "NO") << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
