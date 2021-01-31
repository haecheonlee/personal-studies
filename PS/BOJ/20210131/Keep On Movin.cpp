#include <iostream>
#include <vector>
#include <queue>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(x) (int)(x.size())

using namespace std;

void solve() {
	int N; cin >> N;

	vector<int> odd, even;
	int K = 0;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		
		if(x & 1) odd.push_back(x);
		else even.push_back(x);
		K += (x / 2);
	}
	
	int ans = 0;
	if(sz(odd) <= 1) {
		for(auto& x : odd) ans += x;
		for(auto& x : even) ans += x;
		cout << ans << '\n';
	} else {
		int ans = (K / sz(odd));
		cout << ans * 2 + 1 << '\n';
	}
}

int main() {
	fastio
	
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
