#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 1;

int a[MAX_N];

int main() {
	int N, K; cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N);

	int ans = 0;
	ll L = 1, R = 2e9;
	while(L <= R) {
		ll m = (L + R) / 2;
		
		ll k = 0;
		for(int i = (N + 1) / 2; i <= N; i++) k += max(1LL * 0, m - a[i]);
		
		if(k <= K) ans = m, L = m + 1;
		else R = m - 1;
	}
	cout << ans << '\n';
	
	return 0;
}
