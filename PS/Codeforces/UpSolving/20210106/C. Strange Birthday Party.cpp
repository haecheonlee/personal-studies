#include <iostream>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;

void solve() {
	int N, M;
	cin >> N >> M;
	
	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + N + 1);
	
	int b[M + 1];
	for(int i = 1; i <= M; i++) cin >> b[i];

	int P = 1;
	ll ans = 0;
	
	for(int i = N; i >= 1; i--) {
		if(b[a[i]] <= b[P]) ans += b[a[i]];
		else ans += b[P++];
	}

	cout << ans << '\n';
}

int main() {
	fastio
	
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
