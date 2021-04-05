#include <iostream>

using namespace std;

char move(char x) {
	if(x == 'R') return 'G';
	else if(x == 'G') return 'B';
	else return 'R';
}

void solve() {
	int N, K; cin >> N >> K;
	string s; cin >> s;
	
	int ans = K;
	for(int i = 0; i < N - K + 1; i++) {
		int cnt[3] { 0 };
		char color[3] = { 'R', 'G', 'B' };
		for(int k = i; k < i + K; k++) {
			for(int j = 0; j < 3; j++) {
				if(s[k] != color[j]) cnt[j]++;
				color[j] = move(color[j]);
			}
		}
		for(int j = 0; j < 3; j++) ans = min(ans, cnt[j]);
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
