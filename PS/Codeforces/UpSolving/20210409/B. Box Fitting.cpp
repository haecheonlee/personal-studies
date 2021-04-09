/* reference: editorial */

#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

void solve() {
	int N, W; cin >> N >> W;
	multiset<int> ms;
	
	for(int i = 0; i < N; i++) {
		int w; cin >> w;
		ms.insert(w);
	}
	
	int ans = 1, L = W;
	while(!ms.empty()) {
		auto it = ms.upper_bound(L);
		if(it != ms.begin()) {
			it--;
			int val = *it;
			L -= val;
			ms.erase(it);
		} else {
			L = W;
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
