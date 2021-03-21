#include <iostream>

#define sz(x) (int)x.size()

using namespace std;

void solve() {
	string s, t; cin >> s >> t;
	
	for(int i = 0; i < sz(s); i++) {
		for(int j = 0; j < sz(t); j++) {
			if(s[i] == t[j]) {
				cout << "YES" << '\n';
				return;
			}
		}
	}
	
	cout << "NO" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
