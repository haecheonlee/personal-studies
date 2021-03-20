#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	string p, s; cin >> p >> s;
	sort(p.begin(), p.end());
	
	int N = (int)p.size();
	for(int i = 0; i < s.size(); i++) {
		string ss = s.substr(i, N);
		sort(ss.begin(), ss.end());
		
		if(p == ss) {
			cout << "YES" << '\n';
			return;
		}
	}
	
	cout << "NO" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
