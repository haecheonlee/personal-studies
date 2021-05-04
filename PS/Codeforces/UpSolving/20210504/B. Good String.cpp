#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	string s; cin >> s;

	int cnt1 = 0;
	for(int i = 0; i < N; i++) {
		if(s[i] == '>') break;
		else cnt1++;
	}
	
	int cnt2 = 0;
	for(int i = N - 1; i >= 0; i--) {
		if(s[i] == '<') break;
		else cnt2++;
	}
	
	cout << min(cnt1, cnt2) << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
