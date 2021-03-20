#include <iostream>
#include <set>

using namespace std;

void solve() {
	string s; cin >> s;
	int N = (int)s.size();
	
	if(N == 1) {
		cout << s << '\n';
	} else {
		set<char> ans;
		for(int i = 0; i < N; i++) {
			if(s[i] != s[i + 1]) ans.insert(s[i]);
			else i++;
		}
		
		for(auto it : ans) cout << it;
		cout << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
