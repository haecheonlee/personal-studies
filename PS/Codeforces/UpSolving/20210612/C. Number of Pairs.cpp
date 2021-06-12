#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int N, L, R; cin >> N >> L >> R;
	
	vector<int> a(N);
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a.begin(), a.end());
	
	long long ans = 0;
	for(int i = 0; i < N; i++) {
		ans += upper_bound(a.begin(), a.end(), R - a[i]) - a.begin();
		ans -= lower_bound(a.begin(), a.end(), L - a[i]) - a.begin();
		if(L <= 2 * a[i] && 2 * a[i] <= R) ans--;
	}
	cout << ans / 2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
