#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 0; i < N - 1; i++) {
		int mx = max(a[i], a[i + 1]), mn = min(a[i], a[i + 1]);
		if((mx + mn - 1) / mn > 2) {
			mn *= 2;
			while(mn < mx) {
				mn *= 2;
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
