#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	
	string s(200, 'a');
	cout << s << '\n';
	
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		s[x] = (s[x] == 'a' ? 'b' : 'a');
		cout << s << '\n';
	}
	
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
