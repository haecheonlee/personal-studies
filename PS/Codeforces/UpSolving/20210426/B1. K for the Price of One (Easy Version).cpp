/* reference: gumnam */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5 + 10;

long long a[MAX_N], p[MAX_N];

void solve() {
	int N, P, K; cin >> N >> P >> K;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N);
	for(int i = 1; i < K; i++) p[i] = p[i - 1] + a[i];
	for(int i = K; i <= N; i++) p[i] = a[i] + p[i - K];
	
	int ans = 0;
	for(int i = 1; i <= N; i++) if(p[i] <= P) ans = i;
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
