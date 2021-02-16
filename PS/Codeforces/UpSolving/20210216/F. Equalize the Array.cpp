#include <iostream>
#include <map>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 2e5 + 1;

int a[MAX_N];

void solve() {
	int N; cin >> N;
	
	map<int,int> m;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	
	map<int,int> cnt;
	for(auto it : m) cnt[it.sc]++;

	if(m.size() == 1) {
		cout << 0 << '\n';
	} else {
		int ans = N;
		for(auto it1 : cnt) {
			int sum = 0;
			for(auto it2 : cnt) {
				if(it1.fi == it2.fi) continue;
				if(it1.fi > it2.fi) sum += (it2.fi * it2.sc);
				else sum += (it2.fi - it1.fi) * it2.sc;
			}
			ans = min(ans, sum);
		}
		cout << ans << '\n';
	}
	
}

int main() {
	fastio
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
