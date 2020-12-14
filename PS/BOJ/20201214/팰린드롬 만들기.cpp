#include <iostream>

#define sz(x) (int)(x.size())

using namespace std;

int cnt[26];

int main() {
	string s;
	cin >> s;
	
	for(auto& c : s) cnt[c - 'A']++;
	
	int odd = 0;
	for(int i = 0; i < 26; i++) if(cnt[i]&1) odd++;
	
	if(odd >= 2 || (odd >= 1 && !(sz(s)&1))) {
		cout << "I'm Sorry Hansoo" << '\n';
	} else {
		string ans = "";
		string extra = "" ;
		for(int i = 0; i < 26; i++) {
			if(!cnt[i]) continue;
			
			if(cnt[i]&1) extra = (i + 'A');
			for(int j = 0; j < cnt[i] / 2; j++) ans.push_back('A' + i);
		}
		
		for(int i = 0; i < sz(ans); i++) cout << ans[i];
		cout << extra;
		for(int i = sz(ans) - 1; i >= 0; i--) cout << ans[i];
	}

	return 0;
}
