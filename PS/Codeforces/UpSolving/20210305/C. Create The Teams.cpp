#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 1;

int a[MAX_N];

void solve() {
	int N, X; cin >> N >> X;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	int ans = 0, v = 1e9, cnt = 0;
	for(int i = N - 1; i >= 0; i--) {
		v = min(v, a[i]);
		cnt++;
		
		if(v * cnt >= X) v = a[i], cnt = 0, ans++;
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
