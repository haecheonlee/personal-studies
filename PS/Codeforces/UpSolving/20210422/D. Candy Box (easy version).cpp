#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 10;

int cnt[MAX_N];

void solve() {
	int N; cin >> N;
	
	set<int> s;
	for(int i = 1; i <= N; i++) {
		cnt[i] = 0;
		s.insert(i);
	}
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		cnt[x]++;
	}

	int ans = 0;
	for(int i = 1; i <= N; i++) {
		auto it = s.lower_bound(cnt[i]);
		if(*it == cnt[i]) {
			ans += cnt[i];
			s.erase(it);	
		} else if(it != s.begin()) {
			it--;
			ans += *it;
			s.erase(it);
		}
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
