/* editorial */

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int N; cin >> N;
	string s; cin >> s;
	
	vector<int> t, m;
	for(int i = 0; i < N; i++)
		if(s[i] == 'T') t.push_back(i); else m.push_back(i);
	
	if(t.size() != m.size() * 2) {
		cout << "NO" << '\n';
	} else {
		bool flag = 1;
		for(int i = 0; i < m.size(); i++) {
			if(m[i] < t[i] || m[i] > t[i + m.size()]) flag = 0;
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}
	
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
