#include <iostream>

using namespace std;

const int MAX_N = 1e2 + 1;

int N, U, V;
int a[MAX_N];

int calc(int L, int R) {
	if(abs(L - R) >= 2) return 0;
	if(abs(L - R) == 0) return min(2 * V, U + V);
	return min(U, V);	// abs(L - R) == 1
}

void solve() {
	cin >> N >> U >> V;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int ans = 2e9 + 1;
	for(int i = 1; i <= N; i++) {
		int prv = calc(a[i - 1], a[i]);
		int nxt = calc(a[i + 1], a[i]);
		
		if(i == 1) ans = min(ans, nxt);
		else if(i == N) ans = min(ans, prv);
		else ans = min(ans, min(nxt, prv));
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
