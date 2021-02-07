#include <iostream>

using namespace std;

void solve() {
	string s; cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(i & 1) {
			if(s[i] == 'z') s[i] = 'y';
			else s[i] = 'z';
		} else {
			if(s[i] == 'a') s[i] = 'b';
			else s[i] = 'a';
			
		}
	}
	cout << s << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
