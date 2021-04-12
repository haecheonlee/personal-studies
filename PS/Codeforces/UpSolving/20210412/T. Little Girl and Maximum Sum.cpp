#include <iostream>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 2e5 + 10;

typedef long long ll;

ll a[MAX_N];
ll p[MAX_N], cnt[MAX_N];

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> a[i];
	for(int i = 1; i <= M; i++) {
		int l, r; cin >> l >> r;
		p[l]++, p[r + 1]--;
	}
	
	for(int i = 1; i <= N; i++) {
		p[i] += p[i - 1];
		cnt[i] += p[i];
	}

	sort(cnt + 1, cnt + 1 + N);
	sort(a + 1, a + 1 + N);

	ll ans = 0;
	for(int i = 1; i <= N; i++) ans += a[i] * cnt[i];
	cout << ans << '\n';

	return 0;
}
