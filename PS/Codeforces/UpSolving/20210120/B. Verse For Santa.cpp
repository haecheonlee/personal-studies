#include <iostream>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

void solve() {
	int N, S;
	cin >> N >> S;
	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];

	int ans = 0;
	int now = 0, mx = 0, idx = 0;
	for(int i = 1; i <= N; i++) {
		if(a[i] > mx) mx = a[i], idx = i;
		if(now + a[i] <= S) {
			now += a[i];
		} else {
			cout << idx << '\n';
			return;
		}
	}

	cout << 0 << '\n';
}
int main() {
    fastio
    
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
