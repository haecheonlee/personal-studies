#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e2 + 10;

int p[MAX_N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N, Q; cin >> N >> Q;
	
	while(Q--) {
		int t, k, d; cin >> t >> k >> d;
		vector<int> a;
		for(int i = 1; i <= N && a.size() < k; i++) if(p[i] <= t) a.push_back(i);
		
		if(a.size() == k) {
			int ans = 0;
			for(auto& x : a) p[x] = t + d, ans += x;
			cout << ans << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
	
	return 0;
}
