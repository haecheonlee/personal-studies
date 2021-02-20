/* ediotorial */

#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(x) (int)x.size()

using namespace std;

const int MAX_N = 3e5 + 10;

int a[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	
	cout << (a[0] < a[N - 1] ? "YES" : "NO") << '\n';
}

int main() {
	fastio
	
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
