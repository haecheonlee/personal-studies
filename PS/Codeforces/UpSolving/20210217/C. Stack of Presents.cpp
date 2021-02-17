#include <iostream>

using namespace std;

const int MAX = 1e5 + 1;

int b[MAX], p[MAX];

void solve() {
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		p[x] = i;
	}
	
	for(int i = 1; i <= M; i++) {
		int x; cin >> x;
		b[i] = p[x];
	}
	
	long long ans = 0, L = 0;
	for(int i = 1; i <= M; i++) {
		if(b[i] < L) ans += 1;
		else ans += (2 * (b[i] - i)) + 1, L = b[i];
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
