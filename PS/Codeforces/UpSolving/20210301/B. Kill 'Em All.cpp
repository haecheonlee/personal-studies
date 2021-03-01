#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 1;

int a[MAX_N];

void solve() {
	int N, R; cin >> N >> R;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	int d = 0, ans = 0;
	for(int i = N - 1; i >= 0; i--) {
		while(i > 0 && a[i] == a[i - 1]) i--;
		if(a[i] - d > 0) {
			d = min(100000, d + R);
			ans++;
		}
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
