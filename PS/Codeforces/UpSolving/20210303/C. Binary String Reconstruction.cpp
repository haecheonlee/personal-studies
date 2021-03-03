/* editorial */

#include <iostream>

using namespace std;

void solve() {
	string s; cin >> s;
	int x; cin >> x;
	
	int N = (int)s.size();
	string w(N, '1');
	for(int i = 0; i < N; i++) {
		if(s[i] == '0') {
			if(i - x >= 0) w[i - x] = '0';
			if(i + x < N) w[i + x] = '0';
		}
	}
	
	for(int i = 0; i < N; i++) {
		bool one = false;
		one = one || (i - x >= 0 && w[i - x] == '1');
		one = one || (i + x < N && w[i + x] == '1');
		
		if(s[i] != one + '0') {
			cout << -1 << '\n';
			return;
		}
	}
	
	cout << w << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
