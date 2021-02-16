#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	
	int c[3] {0};	
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		c[x % 3]++;
	}
	
	if(c[0] == c[1] && c[1] == c[2]) {
		cout << 0 << '\n';
	} else {
		int ans = 0;
		while(1) {
			if(c[0] == c[1] && c[1] == c[2]) break;
			for(int i = 0; i < 3; i++) {
				if(c[i] > N / 3) {
					int x = c[i] - (N / 3);
					c[i] -= x;
					c[(i + 1) % 3] += x;
					ans += x;
				}
			}
		}
		cout << ans << '\n';
	}
	
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
