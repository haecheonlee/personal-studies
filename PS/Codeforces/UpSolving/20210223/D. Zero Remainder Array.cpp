#include <iostream>
#include <set>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 2e5 + 10;

int a[MAX_N];

void solve() {
	int N, K; cin >> N >> K;
	
	multiset<int> R;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(a[i] % K != 0) R.insert(K - a[i] % K);
	}

	long long ans = 0;
	int x = 0;
	while(!R.empty()) {
		auto k = R.lower_bound(x);
		if(k != R.end()) {
			ans += (*k - x + 1);
			x = (*k + 1) % K;
			R.erase(k);
		} else {
			ans += (K - x);
			x = 0;
		}
	}
	cout << ans << '\n';
}

int main() {
	fastio

	int T; cin >> T;
	while(T--) solve();

	return 0;
}
