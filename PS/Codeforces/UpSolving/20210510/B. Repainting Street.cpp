#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

void solve() {
	int N, K; cin >> N >> K;
	
	set<int> s;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	
	int ans = N;
	for(auto it = s.begin(); it != s.end(); it++) {
		int cnt = 0;
		for(int i = 1; i <= N; i++) if(a[i] != *it) cnt++, i += K - 1; 
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
