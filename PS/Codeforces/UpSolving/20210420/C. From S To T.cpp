#include <iostream>

using namespace std;

void solve() {
	string s, t, p; cin >> s >> t >> p;
	int a[26] { 0 }, b[26] { 0 };
	
	for(auto& ss : s) a[ss - 'a']++;
	for(auto& pp : p) a[pp - 'a']++;
	for(auto& tt : t) b[tt - 'a']++;
	
	bool flag = 1;
	int x = 0;
	for(int i = 0; i < s.size(); i++) {
		bool found = 0;
		for(int j = x; j < t.size(); j++) {
			if(s[i] == t[j]) {
				found = 1;
				x = j + 1;
				break;
			}
		}
		if(!found) flag = 0;
	}
	
	for(int i = 0; i < 26; i++) if(a[i] < b[i]) flag = 0;
	cout << (flag ? "YES" : "NO") << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
