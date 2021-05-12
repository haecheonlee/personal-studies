#include <iostream>

using namespace std;

void solve() {
	string s; cin >> s;
	s = 'x' + s + 'x';
	
	bool flag = 1;
	for(int i = 1; i < s.size() - 1; i++) {
		if(s[i] == '?') {
			bool a = 1, b = 1, c = 1;
			for(int k = i - 1; k <= i + 1; k++) {
				if(s[k] == 'a') a = 0;
				else if(s[k] == 'b') b = 0;
				else if(s[k] == 'c') c = 0;
			}
			if(a) s[i] = 'a';
			else if(b) s[i] = 'b';
			else if(c) s[i] = 'c';
		} else if(s[i] == s[i + 1]) {
			flag = 0;	
		}
	}
	
	if(flag) cout << s.substr(1, s.size() - 2) << '\n';
	else cout << -1 << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
