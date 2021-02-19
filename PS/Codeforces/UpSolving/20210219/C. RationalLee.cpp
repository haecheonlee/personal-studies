#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 1;

int a[MAX_N], w[MAX_N];

void solve() {
	int N, K; cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> a[i];
	for(int i = 1; i <= K; i++) cin >> w[i];
	sort(a + 1, a + 1 + N); sort(w + 1, w + 1 + K);
	
	int R = N, L = N - K;
	long long ans = 0;
	for(int i = 1; i <= K; i++) {
		if(w[i] == 1) {
			ans += a[R] + a[R];
		} else {
			L = max(0, L - w[i] + 2);
			ans += a[R] + a[L];
			L--;
		}
		
		R--;
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
