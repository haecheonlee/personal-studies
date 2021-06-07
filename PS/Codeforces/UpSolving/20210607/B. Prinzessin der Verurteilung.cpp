#include <iostream>
#include <set>

using namespace std;

set<string> a;

bool go(string& s) {
	for(int i = 0; i < 26; i++) {
		s += ('a' + i);
		if(a.find(s) == a.end()) return true;
		s.pop_back();
	}
	if(s.size() > 1 && s.back() != 'z') return false;
	for(int i = 0; i < 26; i++) {
		s += ('a' + i);
		if(go(s)) return true;
		s.pop_back();
	}
	
	return false;
}

void solve() {
	int N; cin >> N;
	string s; cin >> s;
	
	a.clear();
	
	for(int i = 0; i < N; i++) {
		string x = "";
		for(int j = i; j < N; j++) {
			x += s[j];
			a.insert(x);
		}
	}
	
	string ans = "";
	if(go(ans)) cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
