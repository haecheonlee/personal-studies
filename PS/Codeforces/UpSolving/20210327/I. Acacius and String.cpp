#include <iostream>
#include <stack>

using namespace std;

string cmp = "abacaba";

int count(string& s) {
	int cnt = 0;

	for(int i = 0; i < s.size(); i++) 
		if(s.substr(i, cmp.size()) == cmp) 
			cnt++;
	
	
	return cnt;
}

void solve() {
	int N; cin >> N;
	string s; cin >> s;
	bool chk = 0;
	
	for(int i = 0; i + cmp.size() <= N; i++) {
		string ss = s;
		bool ok = 1;
		
		for(int j = 0; j < cmp.size(); j++) {
			if(ss[i + j] != '?' && ss[i + j] != cmp[j]) {
				ok = false;
				break;
			}
			ss[i + j] = cmp[j];
		}
		
		if(ok && count(ss) == 1) {
			for(int j = 0; j < N; j++) if(ss[j] == '?') ss[j] = 'd';
			cout << "Yes" << '\n';
			cout << ss << '\n';
			return;
		}
	}
	
	cout << "No" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
