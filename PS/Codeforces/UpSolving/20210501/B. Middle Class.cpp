#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

void solve() {
	long long N, x; cin >> N >> x;
	for(int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + 1 + N);
	
	long long ans = 0, sum = 0;
	for(int i = N; i >= 1; i--) {
		long long p = N - i + 1;
		
		sum += a[i];
		if(sum / p < x) break;
		ans = p;
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
