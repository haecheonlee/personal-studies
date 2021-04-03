#include <iostream>

using namespace std;

void solve() {
	string s; cin >> s;
	int N = (int)s.size();
	
	for(int i = 0; i <= N / 2; i++) {
		if(s[i] != s[N - i - 1]) {
			s.insert(i + 1, "a");
			cout << "YES" << '\n';
			cout << s << '\n';
			return;
		} else if(s[i] == s[N - i - 1] && s[i] != 'a') {
			s.insert(i, "a");
			cout << "YES" << '\n';
			cout << s << '\n';
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
