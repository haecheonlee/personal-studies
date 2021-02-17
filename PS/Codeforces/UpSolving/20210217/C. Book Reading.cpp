#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	long long N, M; cin >> N >> M;

	if(N < M) {
		cout << 0 << '\n';
	} else {
		long long m = M % 10;
		
		set<int> p;
		vector<int> d;
		if(m == 1) {
			for(int i = 1; i <= 10; i++) d.push_back(i % 10);
		} else {
			int L = 2;
			long long now  = m;
			while(p.find(now) == p.end()) {
				p.insert(now); d.push_back(now);
				now = m * (L++);
				now %= 10;
			}
		}
		
		long long k = N / M;
		long long kk = k / (d.size());
		
		long long ans = 0;
		for(auto& x : d) ans += (kk * x);
		for(int i = 0; i < k - (kk * d.size()); i++) ans += d[i];
		cout << ans << '\n';
	}

}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
