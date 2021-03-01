/* editorial */

#include <iostream>
#include <set>

using namespace std;

void solve() {
	int N, K; cin >> N >> K;
	set<int> s;
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		s.insert(x);
	}
	
	if(s.size() > K) {
		cout << -1 << '\n';
		return;
	} else {
		cout << N * K << '\n';
		for(int i = 0; i < N; i++) {
			for(auto x : s) cout << x << ' ';
			for(int j = 0; j < K - s.size(); j++) cout << 1 << ' ';
		}
		cout << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
