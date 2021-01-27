/* reference: editorial */

#include <iostream>

using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	
	int ans = N;
	for(int i = 1; i * i <= N; i++) {
		if(N % i == 0) {
			if(i <= K) ans = min(ans, N / i);
			if(N / i <= K) ans = min(ans, i);
		}
	}
	cout << ans << '\n';
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
