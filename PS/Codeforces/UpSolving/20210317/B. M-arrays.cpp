#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1e5 + 1;

int cnt[MAX];

void solve() {
	int N, M; cin >> N >> M;
	
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		cnt[x % M]++;
	}
	
	int ans = (cnt[0] ? 1 : 0);
	for(int i = 1; i <= (M / 2); i++) {
		if(cnt[i] || cnt[M - i])
			ans += 1 + max(abs(cnt[i] - cnt[M - i]) - 1, 0);
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
